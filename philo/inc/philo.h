/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/05/29 16:11:50 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>     // memset
# include <stdio.h>      // printf
# include <stdlib.h>     // malloc, free
# include <unistd.h>     // write, usleep
# include <sys/time.h>   // gettimeofday
# include <pthread.h>    // pthread_* functions
# include <stddef.h>	 // size_t

typedef struct s_data
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_data;

#endif
