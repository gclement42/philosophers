/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:13:57 by gclement          #+#    #+#             */
/*   Updated: 2023/05/10 14:54:12 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(struct timeval start, t_philo *philo)
{
	philo->fork.available = FALSE;
	philo->fork_right->available = FALSE;
	pthread_mutex_lock(&philo->fork_right->mutex);
	pthread_mutex_lock(&philo->fork.mutex);
	printf("%ldms %d has taken a fork\n", time_diff(&start), philo->number);
}

void	is_dying(struct timeval start, t_philo *philo)
{
	double			time;

	time = time_diff(&philo->last_meal);
	if (time >= philo->time_to.time_to_die)
		exit (printf("\033[0;31m%ldms %d is died\033[0m\n"
				, time_diff(&start), philo->number));
}

void	is_eat(struct timeval start, t_philo *philo)
{
	if (!philo->fork_right)
		exit (printf("\033[0;31m%ldms %d died\033[0m\n"
				, time_diff(&start), philo->number));
	if (philo->fork.available == FALSE \
		|| philo->fork_right->available == FALSE)
		is_dying(start, philo);
	take_fork(start, philo);
	printf("%ldms %d is eating\n", time_diff(&start), philo->number);
	is_dying(start, philo);
	usleep(philo->time_to.time_to_eat * 1000);
	philo->count_eat++;
	is_dying(start, philo);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->fork_right->mutex);
	pthread_mutex_unlock(&philo->fork.mutex);
	philo->fork.available = TRUE;
	philo->fork_right->available = TRUE;
	printf("%ldms %d has been putting a fork\n", \
		time_diff(&start), philo->number);
}

void	is_sleep(struct timeval start, t_philo *philo)
{
	printf("%ldms %d is sleeping\n", time_diff(&start), philo->number);
	is_dying(start, philo);
	usleep(philo->time_to.time_to_sleep * 1000);
	is_dying(start, philo);
}

void	is_think(struct timeval start, t_philo *philo)
{
	printf("%ldms %d is thinking\n", time_diff(&start), philo->number);
	while (1)
	{
		is_dying(start, philo);
		if (philo->fork.available == TRUE
			&& philo->fork_right->available == TRUE)
			break ;
	}
	return ;
}
