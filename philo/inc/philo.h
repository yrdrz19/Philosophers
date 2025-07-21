/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:11 by yaperalt          #+#    #+#             */
/*   Updated: 2025/07/18 14:58:26 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define COLOR_DIED "\x1b[31m"
# define COLOR_TAKEN "\x1b[33m"
# define COLOR_EATING "\x1b[32m"
# define COLOR_SLEEPING "\x1b[36m"
# define COLOR_THINKING "\x1b[35m"
# define RESET "\x1b[0m"

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
// uint64_t
# include <stdint.h>

struct s_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_id;
	long			start_time;
	int				must_eat;
	bool			died;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	struct s_philo	*philosophers;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	uint64_t		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		monitor;
	t_data			*data;
}	t_philo;

//init.c
void		init_philos(int argc, char **argv, t_data *data);
void		init_forks_and_philos(t_data *data);

// print.c
void		print_eating(t_philo *philo);
void		print_sleeping(t_philo *philo);
void		print_thinking(t_philo *philo);
void		print_taking(t_philo *philo);
void		print_died(t_philo *philo);

// utils.c
int			ft_atoi(const char *str);
void		display_error_message(void);
bool		ft_atoi_boolean(const char *str);
int			check_arguments(int argc, char **argv);

// time.c
__uint64_t	get_current_time(void);
void		precise_usleep(uint64_t time);

#endif
