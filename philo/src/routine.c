/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:20:39 by yz                #+#    #+#             */
/*   Updated: 2025/09/25 17:33:12 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_taking(ph);
	if (ph->data->n_philo == 1)
	{
		precise_usleep(ph->data->t_die + 1);
		pthread_mutex_unlock(ph->left_fork);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	print_taking(ph);
	print_eating(ph);
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal = get_current_time();
	ph->eat_count++;
	pthread_mutex_unlock(&ph->meal_mutex);
	precise_usleep(ph->data->t_eat);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(ph->left_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(1000);
	while (!should_stop(ph->data))
	{
		philo_eat(ph);
		if (should_stop(ph->data))
			break ;
		pthread_mutex_lock(&ph->meal_mutex);
		if (ph->data->must_eat != -1 && ph->eat_count >= ph->data->must_eat)
		{
			pthread_mutex_unlock(&ph->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&ph->meal_mutex);
		print_sleeping(ph);
		precise_usleep(ph->data->t_sleep);
		print_thinking(ph);
	}
	return (NULL);
}

bool	should_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->state_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->state_mutex);
	return (stop);
}

void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->stop = true;
	pthread_mutex_unlock(&data->state_mutex);
}

void	announce_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->state_mutex);
	if (!ph->data->stop)
	{
		ph->data->died = true;
		ph->data->stop = true;
		pthread_mutex_unlock(&ph->data->state_mutex);
		print_died(ph);
	}
	else
		pthread_mutex_unlock(&ph->data->state_mutex);
}
