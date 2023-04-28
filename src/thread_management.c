/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:37 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 14:24:09 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_t	*create_all_thread(int number_of_philosophers, t_time_to time_to)
{
	int			i;
	t_philo		philo;
	pthread_t	*thread_id;

	i = 0;
	thread_id = malloc(sizeof(pthread_t) * number_of_philosophers);
	if (!thread_id)
		return (NULL);
	while (i < number_of_philosophers)
	{
		philo = create_philosopher(time_to, i);
		thread_id[i] = create_thread(&philo);
		pthread_join(thread_id[i], NULL);
		i++;
	}
	return (thread_id);
}

pthread_t	create_thread(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, philosopher_routine, (void *)philo);
	printf("creation du thread N.%d\n", philo->number);
	return (thread);
}

void	wait_thread(pthread_t *thread_id, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
}

