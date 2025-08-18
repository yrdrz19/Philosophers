/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:20 by yaperalt          #+#    #+#             */
/*   Updated: 2025/08/08 12:16:02 by yz               ###   ########.fr       */
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
	init_forks_and_philos(&data);
	start_simulation(&data);
	cleanup_and_exit(&data);
	return (EXIT_SUCCESS);
}
