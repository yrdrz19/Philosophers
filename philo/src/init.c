/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:41:58 by yaperalt          #+#    #+#             */
/*   Updated: 2025/08/08 12:16:02 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philos(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->died = false;
	data->stop = false;
	data->finished = 0;
	data->start_time = 0;
	data->philosophers = malloc(sizeof(t_philo) * data->n_philo);
	data->threads = malloc(sizeof(pthread_t) * data->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->state_mutex, NULL);
}

void	init_forks_and_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].data = data;
		data->philosophers[i].eat_count = 0;
		data->philosophers[i].last_meal = -1;
		data->philosophers[i].left_fork = &data->forks[i];
		if (i == data->n_philo - 1)
			data->philosophers[i].right_fork = &data->forks[0];
		else
			data->philosophers[i].right_fork = &data->forks[i + 1];
		pthread_mutex_init(&data->philosophers[i].meal_mutex, NULL);
		i++;
	}
}

