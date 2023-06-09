/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:07 by gclement          #+#    #+#             */
/*   Updated: 2023/05/30 09:37:33 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time_to	init_arg_struct(char *argv[])
{
	t_time_to	time_to;

	time_to.die = ft_atoi(argv[2]);
	time_to.eat = ft_atoi(argv[3]);
	time_to.sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		time_to.nb_times_must_eat = ft_atoi(argv[5]);
		time_to.b_must_eat = TRUE;
	}
	else
	{
		time_to.nb_times_must_eat = -1;
		time_to.b_must_eat = FALSE;
	}
	return (time_to);
}

int	check_arg(char *argv[], int *number_of_philosopher, t_time_to time_to)
{
	if (time_to.die < 1 || time_to.eat < 1
		|| time_to.sleep < 1
		|| (time_to.nb_times_must_eat < 1 && time_to.b_must_eat == TRUE))
		return (printf("not the good arguments\n"), 0);
	*number_of_philosopher = ft_atoi(argv[1]);
	if (*number_of_philosopher < 1)
		return (printf("not the good arguments\n"), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_time_to	time_to;
	pthread_t	*thread_id;
	int			number_of_philosopher;
	t_philo		*philosophers;

	if ((argc == 5 || argc == 6))
		time_to = init_arg_struct(argv);
	else
		return (printf("not the right number of arguments\n"), 0);
	if (!check_arg(argv, &number_of_philosopher, time_to))
		return (0);
	philosophers = create_all_philosophers(number_of_philosopher, time_to);
	if (!philosophers)
		return (0);
	thread_id = create_all_thread(number_of_philosopher, philosophers);
	if (!thread_id)
		return (0);
	check_if_die(philosophers, thread_id, number_of_philosopher);
	wait_thread(thread_id, philosophers, number_of_philosopher);
	return (0);
}
