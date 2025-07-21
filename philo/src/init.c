/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:41:58 by yaperalt          #+#    #+#             */
/*   Updated: 2025/07/14 07:42:10 by yaperalt         ###   ########.fr       */
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
	data->philosophers = malloc(sizeof(t_philo) * data->n_philo);
	data->threads = malloc(sizeof(pthread_t) * data->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) *data->n_philo);
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
	}
}

