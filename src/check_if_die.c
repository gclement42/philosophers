/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:21:48 by gclement          #+#    #+#             */
/*   Updated: 2023/05/11 14:53:28 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dying(struct timeval start, t_philo *philo)
{
	double			time;

	time = time_diff(&philo->last_meal);
	// printf("time = %ld")
	if (time > philo->time_to.die)
	{
		philo->is_dead = TRUE;
		printf("\033[0;31m%ldms %d died\033[0m\n"
			, time_diff(&start), philo->number);
	}
}

void	check_if_die(t_philo *philosophers, int number_of_philosophers)
{
	int		i;

	i = 0;
	while (1)
	{
		is_dying(philosophers[i].last_meal, &philosophers[i]);
		if (philosophers[i].is_dead)
			break ;
		if (i < number_of_philosophers)
			i++;
		else
			i = 0;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		philosophers[i].is_dead = TRUE;
		i++;
	}
}
