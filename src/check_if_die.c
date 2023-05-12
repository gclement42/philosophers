/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:21:48 by gclement          #+#    #+#             */
/*   Updated: 2023/05/11 15:31:11 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dying(t_philo *philo)
{
	double			time;

	time = time_diff(&philo->last_meal);
	if ((philo->time_to.nb_times_must_eat > 0 \
		&& philo->count_eat == philo->time_to.nb_times_must_eat))
		return ;
	if (time > philo->time_to.die)
	{
		philo->is_dead = TRUE;
		printf("\033[0;31m%ldms %d died\033[0m\n"
			, time_diff(&philo->time_start), philo->number);
	}
}

void	check_if_die(t_philo *philosophers, int number_of_philosophers)
{
	int		i;
	t_philo	*p_philo;
	//int		count;

	i = 0;
	//count = 0;
	while (1)
	{
		is_dying(&philosophers[i]);
		// if ((philosophers[i].time_to.nb_times_must_eat > 0 
		// && philosophers[i].count_eat == philosophers[i].time_to.nb_times_must_eat))
		// 	count++;
		// if (count == number_of_philosophers - 1)
		// 	break ;
		if (philosophers[i].is_dead)
			break ;
		if (i < number_of_philosophers - 1)
			i++;
		else
			i = 0;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		p_philo = &philosophers[i];
		p_philo->is_dead = TRUE;
		i++;
	}
	free(philosophers);
}
