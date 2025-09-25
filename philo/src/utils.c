/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:31:27 by yaperalt          #+#    #+#             */
/*   Updated: 2025/09/10 15:25:49 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	pos;

	sign = 1;
	result = 0;
	pos = 0;
	while (str[pos] == ' ' || str[pos] == '\f' || str[pos] == '\n'
		|| str[pos] == '\r' || str[pos] == '\t' || str[pos] == '\v')
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			sign *= -1;
		pos++;
	}
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		result = (result * 10) + (str[pos] - '0');
		pos++;
	}
	return (result * sign);
}

void	display_error_message(void)
{
	printf("-----------/ Philosophers /-----------\n\n");
	printf("This program accepts 4 or 5 extra arguments\n");
	printf("./philo\n");
	printf("number_of_philosophers\n");
	printf("time_to_die\n");
	printf("time_to_eat\n");
	printf("time_to_eat time_to_sleep\n");
	printf("[number_of_times_each_philosopher_must_eat](optional)\n\n");
	printf("Time will be interpreted in milliseconds\n\n");
}

bool	ft_atoi_boolean(const char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] == ' ' || str[pos] == '\f' || str[pos] == '\n'
		|| str[pos] == '\r' || str[pos] == '\t' || str[pos] == '\v')
		pos++;
	if (str[pos] == '-')
		return (false);
	while (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	if (str[pos] == '\0')
		return (true);
	else
		return (false);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_atoi_boolean(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
