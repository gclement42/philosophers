/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:13:57 by gclement          #+#    #+#             */
/*   Updated: 2023/05/15 15:44:50 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(struct timeval start, t_philo *philo)
{
	philo->fork.available = FALSE;
	philo->fork_right->available = FALSE;
	if (philo->number == philo->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->fork_right->mutex);
		pthread_mutex_lock(&philo->fork.mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->fork.mutex);
		pthread_mutex_lock(&philo->fork_right->mutex);
	}
	if (philo->is_dead == FALSE)
		printf("%ldms %d has taken a fork\n", time_diff(&start), philo->number);
}

void	is_eat(struct timeval start, t_philo *philo)
{
	if (!philo->fork_right)
		usleep(philo->time_to.die * 1000);
	take_fork(start, philo);
	if (philo->is_dead == FALSE)
		printf("%ldms %d is eating\n", time_diff(&start), philo->number);
	usleep(philo->time_to.eat * 1000);
	philo->count_eat++;
	gettimeofday(&philo->last_meal, NULL);
	if (philo->number == philo->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->fork_right->mutex);
		pthread_mutex_unlock(&philo->fork.mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork.mutex);
		pthread_mutex_unlock(&philo->fork_right->mutex);
	}
	philo->fork.available = TRUE;
	philo->fork_right->available = TRUE;
	if (philo->is_dead == FALSE)
		printf("%ldms %d has been putting a fork\n", \
		time_diff(&start), philo->number);
}

void	is_sleep(struct timeval start, t_philo *philo)
{
	if (philo->is_dead == FALSE)
		printf("%ldms %d is sleeping\n", time_diff(&start), philo->number);
	usleep(philo->time_to.sleep * 1000);
}

void	is_think(struct timeval start, t_philo *philo)
{
	if (philo->is_dead == FALSE)
		printf("%ldms %d is thinking\n", time_diff(&start), philo->number);
	usleep(philo->time_to.eat * 1000);
	return ;
}
