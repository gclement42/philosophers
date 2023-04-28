/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:07 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 13:50:37 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time_to	init_arg_struct(char *argv[])
{
	t_time_to	time_to;

	time_to.time_to_die = ft_atoi(argv[2]);
	time_to.time_to_eat = ft_atoi(argv[3]);
	time_to.time_to_sleep = ft_atoi(argv[4]);
	return (time_to);
}


int	main(int argc, char *argv[])
{
	t_time_to	time_to;

	if (argc == 5 || argc == 6)
		time_to = init_arg_struct(argv);
	else
		return (printf("not the right number of arguments\n"), 0);
	create_all_thread(ft_atoi(argv[1]), time_to);
	return (0);
}
