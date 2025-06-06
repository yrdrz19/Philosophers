/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:31:27 by yaperalt          #+#    #+#             */
/*   Updated: 2025/05/28 15:52:19 by yaperalt         ###   ########.fr       */
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
