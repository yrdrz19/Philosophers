/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:39:08 by yaperalt          #+#    #+#             */
/*   Updated: 2025/08/08 12:16:02 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_taking(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->state_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_current_time() - philo->data->start_time;
	printf(COLOR_TAKEN"%llu %d has taken a fork\n"RESET, (unsigned long long)time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_eating(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->state_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_current_time() - philo->data->start_time;
	printf(COLOR_EATING"%llu %d is eating\n"RESET, (unsigned long long)time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_sleeping(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->state_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_current_time() - philo->data->start_time;
	printf(COLOR_SLEEPING"%llu %d is sleeping\n"RESET, (unsigned long long)time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_thinking(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->state_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_current_time() - philo->data->start_time;
	printf(COLOR_THINKING"%llu %d is thinking\n"RESET, (unsigned long long)time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_died(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_current_time() - philo->data->start_time;
	printf(COLOR_DIED"%llu %d died\n"RESET, (unsigned long long)time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
