/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:37 by gclement          #+#    #+#             */
/*   Updated: 2023/05/10 14:52:59 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*create_all_thread(
	int number_of_philosophers, t_philo *philosophers)
{
	int			i;
	pthread_t	*thread_id;

	i = 0;
	thread_id = malloc(sizeof(pthread_t) * number_of_philosophers);
	if (!thread_id)
		return (free(philosophers), NULL);
	while (i < number_of_philosophers)
	{
		philosophers->id = create_thread(&philosophers[i]);
		usleep(50);
		thread_id[i] = philosophers->id;
		i++;
	}
	return (thread_id);
}

pthread_t	create_thread(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, philosopher_routine, (void *)philo);
	printf("\e[33mcreation du thread N.%d\e[0m\n", philo->number);
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


