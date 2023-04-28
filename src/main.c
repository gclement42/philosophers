/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:07 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 14:02:02 by gclement         ###   ########.fr       */
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
	pthread_t	*thread_id;
	int			number_of_philosopher;

	number_of_philosopher = ft_atoi(argv[1]);
	if (argc == 5 || argc == 6)
		time_to = init_arg_struct(argv);
	else
		return (printf("not the right number of arguments\n"), 0);
	thread_id = create_all_thread(number_of_philosopher, time_to);
	wait_thread(thread_id, number_of_philosopher);
	return (0);
}
