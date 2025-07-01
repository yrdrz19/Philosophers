/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:39:08 by yaperalt          #+#    #+#             */
/*   Updated: 2025/07/01 10:05:29 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_taking(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->data->start_time;
	printf(COLOR_TAKEN"%ld %d has taken a fork\n"RESET, time, philo->id);
}

void	print_eating(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->data->start_time;
	printf(COLOR_EATING"%ld %d is eating\n"RESET, time, philo->id);
}

void	print_sleeping(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->data->start_time;
	printf(COLOR_SLEEPING"%ld %d is sleeping\n"RESET, time, philo->id);
}

void	print_thinking(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->data->start_time;
	printf(COLOR_THINKING"%ld %d is thinking\n"RESET, time, philo->id);
}

void	print_died(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->data->start_time;
	printf(COLOR_DIED"%ld %d died\n"RESET, time, philo->id);
}
