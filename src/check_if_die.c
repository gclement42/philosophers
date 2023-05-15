/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:21:48 by gclement          #+#    #+#             */
/*   Updated: 2023/05/15 16:26:13 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dying(t_philo *philo)
{
	double			time;

	time = time_diff(&philo->last_meal);
	if (time > philo->time_to.die && philo->stop == FALSE)
	{
		philo->is_dead = TRUE;
		printf("\033[0;31m%ldms %d died\033[0m\n"
			, time_diff(&philo->time_start), philo->number);
	}
}

void	check_if_die(t_philo *philosophers, int number_of_philosophers)
{
	int		i;
	int		count;

	i = 0;
	while (1)
	{
		count = 0;
		is_dying(&philosophers[i]);
		while (count < number_of_philosophers - 1
			&& philosophers[count].stop == TRUE)
			count++;
		if (philosophers[i].is_dead || count == number_of_philosophers - 1)
			break ;
		if (i < number_of_philosophers - 1)
			i++;
		else
			i = 0;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		philosophers[i].is_dead = TRUE;
		pthread_mutex_lock(&philosophers[i].fork.mutex);
		pthread_mutex_unlock(&philosophers[i].fork.mutex);
		pthread_mutex_destroy(&philosophers[i].fork.mutex);
		i++;
	}
	free(philosophers);
}
