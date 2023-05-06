/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:27:55 by gclement          #+#    #+#             */
/*   Updated: 2023/04/29 16:10:21 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Routine du philosophe : Manger->Dormir->Penser
void	*philosopher_routine(void *data)
{
	t_philo			*philo;
	struct timeval	end;

	philo = (t_philo *)data;
	pthread_join(philo->id, NULL);
	while (1)
	{
		is_eat(philo->time_start, philo);
		gettimeofday(&end, NULL);
		is_sleep(philo->time_start, philo);
		is_think(philo->time_start, philo);
	}
	return (NULL);
}

t_philo	create_philosopher(t_time_to time_to, struct timeval time_start, int nb)
{
	t_philo	philo;

	philo.number = nb + 1;
	philo.time_to = time_to;
	philo.fork_available = TRUE;
	philo.time_start = time_start;
	pthread_mutex_init(&philo.mutex, NULL);
	return (philo);
}

void	place_around_table(t_philo *philosophers, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (i == 0)
			philosophers[i].left = &philosophers[number_of_philosophers - 1];
		else
			philosophers[i].left = &philosophers[i - 1];
		if (i == number_of_philosophers - 1)
			philosophers[i].right = &philosophers[0];
		else
			philosophers[i].right = &philosophers[i + 1];
		i++;
	}
}

t_philo	*create_all_philosophers(int number_of_philosophers, t_time_to time_to)
{
	t_philo			*philosophers;
	struct timeval	time_start;
	int				i;

	i = 0;
	philosophers = malloc(sizeof(t_philo) * number_of_philosophers);
	if (!philosophers)
		return (NULL);
	gettimeofday(&time_start, NULL);
	while (i < number_of_philosophers)
	{
		philosophers[i] = create_philosopher(time_to, time_start, i);
		i++;
	}
	place_around_table(philosophers, number_of_philosophers);
	return (philosophers);
}
