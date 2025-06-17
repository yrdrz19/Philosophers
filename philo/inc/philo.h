/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/06/15 18:00:35 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc, free
# include <stdlib.h>
// write, usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread_* functions
# include <pthread.h>
// size_t
# include <stddef.h>
// bool
# include <stdbool.h>

typedef struct s_data
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_data;

// utils.c
int		ft_atoi(const char *str);
void	display_error_message(void);
bool	ft_atoi_boolean(const char *str);
int		check_arguments(int argc, char **argv);

#endif
