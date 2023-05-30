/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:37 by gclement          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:12 by gclement         ###   ########.fr       */
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
	return (thread);
}

void	wait_thread(pthread_t *thread_id, t_philo *philosophers, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&philosophers[i].fork.mutex);
		i++;
	}
	free(thread_id);
	free(philosophers);
}


