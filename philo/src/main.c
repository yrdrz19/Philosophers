/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:20 by yaperalt          #+#    #+#             */
/*   Updated: 2025/07/08 15:06:26 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		display_error_message();
		return (EXIT_FAILURE);
	}
	if (!check_arguments(argc, argv))
	{
		printf("\n Invalid argument format\n\n");
		display_error_message();
		return (EXIT_FAILURE);
	}
	init_philos(argc, argv, &data);
	return (EXIT_SUCCESS);
}
