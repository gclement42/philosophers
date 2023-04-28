/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:27:55 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 13:53:52 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Routine du philosophe : Manger->Dormir->Penser
void	*philosopher_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("Thread : Philosopher N.%d\n", philo->number);
	return (NULL);
}

t_philo	create_philosopher(t_time_to time_to, int nb)
{
	t_philo	philo;

	philo.number = nb;
	philo.time_to = time_to;
	return (philo);
}
