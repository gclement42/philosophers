/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:27:55 by gclement          #+#    #+#             */
/*   Updated: 2023/05/30 13:16:44 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Routine du philosophe : Manger->Dormir->Penser
void	*philosopher_routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->number % 2 == 1)
		usleep(philo->time_to.eat * 1000);
	while (philo->is_dead == FALSE)
	{
		if (!philo->fork_right)
			break ;
		is_eat(philo->time_start, philo);
		is_sleep(philo->time_start, philo);
		is_think(philo->time_start, philo);
		if ((philo->time_to.nb_times_must_eat > 0 \
			&& philo->count_eat == philo->time_to.nb_times_must_eat))
		{
			if (philo->fork.available == FALSE)
				philo->fork.available = TRUE;
			philo->stop = TRUE;
			break ;
		}
	}
	return (NULL);
}

t_philo	create_philosopher(t_time_to time_to, struct timeval time_start, int nb)
{
	t_philo	philo;

	philo.number = nb + 1;
	philo.is_dead = FALSE;
	philo.id = 0;
	philo.time_to = time_to;
	philo.fork.available = TRUE;
	philo.fork.destroy = FALSE;
	philo.time_start = time_start;
	philo.last_meal = time_start;
	philo.stop = FALSE;
	philo.count_eat = 0;
	pthread_mutex_init(&philo.fork.mutex, NULL);
	return (philo);
}

void	place_around_table(t_philo *philosophers, int number_of_philosophers)
{
	int	i;

	i = 0;
	if (number_of_philosophers == 1)
		philosophers[i].fork_right = NULL;
	while (i < number_of_philosophers && number_of_philosophers != 1)
	{
		if (i == number_of_philosophers - 1)
			philosophers[i].fork_right = &philosophers[0].fork;
		else
			philosophers[i].fork_right = &philosophers[i + 1].fork;
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
	if (gettimeofday(&time_start, NULL) == -1)
		return (printf("philo : gettimeofday error\n"), NULL);
	while (i < number_of_philosophers)
	{
		philosophers[i] = create_philosopher(time_to, time_start, i);
		philosophers[i].number_of_philosophers = number_of_philosophers;
		i++;
	}
	place_around_table(philosophers, number_of_philosophers);
	return (philosophers);
}
