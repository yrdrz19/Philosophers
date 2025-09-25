/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:23:06 by yaperalt          #+#    #+#             */
/*   Updated: 2025/09/10 15:27:31 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool	should_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->state_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->state_mutex);
	return (stop);
}

static void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->stop = true;
	pthread_mutex_unlock(&data->state_mutex);
}

static void	announce_death(t_philo *ph)
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

static void	*monitor_all(void *arg)
{
	t_data		*data;
	uint64_t	now;
	int			all_done;
	int			i;

	data = (t_data *)arg;
	while (!should_stop(data))
	{
		all_done = 0;
		i = 0;
		now = get_current_time();
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->philosophers[i].meal_mutex);
			if (data->philosophers[i].last_meal && (now - data->philosophers[i].last_meal >= (uint64_t)data->t_die))
			{
				pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
				announce_death(&data->philosophers[i]);
				return (NULL);
			}
			if (data->must_eat != -1
				&& (data->philosophers[i].eat_count >= data->must_eat))
				all_done++;
			pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
			i++;
		}
		if (data->must_eat != -1 && all_done == data->n_philo)
		{
			set_stop(data);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}

static void	philo_eat(t_philo *ph)
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

static void	*philo_routine(void *arg)
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

void	start_simulation(t_data *data)
{
	int i;

	data->start_time = get_current_time();
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philosophers[i].meal_mutex);
		data->philosophers[i].last_meal = data->start_time;
		pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
		pthread_create(&data->threads[i], NULL, philo_routine, &data->philosophers[i]);
		i++;
	}
	pthread_create(&data->monitor_thread, NULL, monitor_all, data);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	set_stop(data);
	pthread_join(data->monitor_thread, NULL);
}

void	cleanup_and_exit(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (data->forks && i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	i = 0;
	while (data->philosophers && i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philosophers[i].meal_mutex);
		i++;
	}
	if (data->forks)
		free(data->forks);
	if (data->threads)
		free(data->threads);
	if (data->philosophers)
		free(data->philosophers);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}
