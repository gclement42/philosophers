/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:27:55 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 15:19:58 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Routine du philosophe : Manger->Dormir->Penser
void	*philosopher_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("Thread : Philosopher N.%d\n", philo->number);
	philo->state = SLEEP;
	return (NULL);
}

t_philo	create_philosopher(t_time_to time_to, int nb)
{
	t_philo	philo;

	philo.number = nb + 1;
	philo.time_to = time_to;
	philo.fork_available = TRUE;
	return (philo);
}
