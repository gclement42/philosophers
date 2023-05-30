/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:21:48 by gclement          #+#    #+#             */
/*   Updated: 2023/05/30 13:16:31 by gclement         ###   ########.fr       */
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

static void	kill_all(int number_of_philosophers, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		philosophers[i].is_dead = TRUE;
		i++;
	}
}

void	check_if_die(t_philo *philosophers,
	pthread_t *thread_id, int number_of_philosophers)
{
	int		i;
	int		count;

	i = 0;
	(void) thread_id;
	while (1)
	{
		count = 0;
		is_dying(&philosophers[i]);
		while (count < number_of_philosophers - 1
			&& philosophers[count].stop == TRUE)
			count++;
		if (philosophers[i].is_dead == TRUE || \
			(count == number_of_philosophers - 1
				&& number_of_philosophers != 1))
			break ;
		if (i < number_of_philosophers - 1 && number_of_philosophers != 1)
			i++;
		else
			i = 0;
	}
	kill_all(number_of_philosophers, philosophers);
}
