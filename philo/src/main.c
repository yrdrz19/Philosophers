/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:20 by yaperalt          #+#    #+#             */
/*   Updated: 2025/06/15 17:04:56 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		display_error_message();
		return (0);
	}
	if (!check_arguments(argc, argv))
	{
		printf("\n Invalid argument format\n\n");
		display_error_message();
		return (0);
	}

	return (1);
}
