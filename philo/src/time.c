/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:55:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/07/08 17:45:34 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * Creates a variable tv of type struct timeval, defined in <sys/time.h>
 *
 * tv_sec: the number of whole seconds since the Unix epoch (January 1, 1970).
 * tv_usec: the number of microseconds (millionths of a second) that have
 * occurred since the last whole second in tv_sec
 *
 * The epoch in computing is a reference point from which time is measured.
 */
__uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * The purpose is to pause(sleep) the current thread for and accurate
 * amount of time, time in milliseconds.
 */
void	precise_usleep(uint64_t time)
{
	uint64_t start = get_time();
	while (get_time() - start < time)
		usleep(500);
}

