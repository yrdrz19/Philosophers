/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:23:06 by yaperalt          #+#    #+#             */
/*   Updated: 2025/09/25 17:33:12 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_philosopher_death(t_data *data, uint64_t now)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->phs[i].meal_mutex);
		if (data->phs[i].last_meal && (now - data->phs[i].last_meal
				>= (uint64_t)data->t_die))
		{
			pthread_mutex_unlock(&data->phs[i].meal_mutex);
			announce_death(&data->phs[i]);
			return (1);
		}
		pthread_mutex_unlock(&data->phs[i].meal_mutex);
		i++;
	}
	return (0);
}

static int	check_all_finished(t_data *data)
{
	int	all_done;
	int	i;

	if (data->must_eat == -1)
		return (0);
	all_done = 0;
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->phs[i].meal_mutex);
		if (data->phs[i].eat_count >= data->must_eat)
			all_done++;
		pthread_mutex_unlock(&data->phs[i].meal_mutex);
		i++;
	}
	if (all_done == data->n_philo)
	{
		set_stop(data);
		return (1);
	}
	return (0);
}

static void	*monitor_all(void *arg)
{
	t_data		*data;
	uint64_t	now;

	data = (t_data *)arg;
	while (!should_stop(data))
	{
		now = get_current_time();
		if (check_philosopher_death(data, now))
			return (NULL);
		if (check_all_finished(data))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->phs[i].meal_mutex);
		data->phs[i].last_meal = data->start_time;
		pthread_mutex_unlock(&data->phs[i].meal_mutex);
		pthread_create(&data->threads[i], NULL, philo_routine, &data->phs[i]);
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
	while (data->phs && i < data->n_philo)
	{
		pthread_mutex_destroy(&data->phs[i].meal_mutex);
		i++;
	}
	if (data->forks)
		free(data->forks);
	if (data->threads)
		free(data->threads);
	if (data->phs)
		free(data->phs);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}
