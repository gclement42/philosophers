/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:37 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 15:21:33 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_t	*create_all_thread(int number_of_philosophers, t_time_to time_to)
{
	int			i;
	t_philo		*philosophers;
	pthread_t	*thread_id;

	i = 0;
	philosophers = malloc(sizeof(t_philo) * number_of_philosophers);
	if (!philosophers)
		return (NULL);
	thread_id = malloc(sizeof(pthread_t) * number_of_philosophers);
	if (!thread_id)
		return (free(philosophers), NULL);
	while (i < number_of_philosophers)
	{
		philosophers[i] = create_philosopher(time_to, i);
		thread_id[i] = create_thread(&philosophers[i]);
		pthread_join(thread_id[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		printf("state of philosophe : %d\n", philosophers[i].state);
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

