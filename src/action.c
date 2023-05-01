/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:13:57 by gclement          #+#    #+#             */
/*   Updated: 2023/04/29 16:09:09 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eat(struct timeval start, t_philo *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	usleep(philo->time_to.time_to_die);
	if (philo->left->fork_available == TRUE
		&& philo->right->fork_available == TRUE)
	{
		printf("%f N.%d has taken a fork\n", time_diff(&start, &end), philo->number);
		philo->left->fork_available = FALSE;
		philo->right->fork_available = FALSE;
		pthread_mutex_lock(&philo->right->mutex);
		pthread_mutex_lock(&philo->left->mutex);
		philo->state = EAT;
		printf("%f N.%d is eating\n", time_diff(&start, &end), philo->number);
		usleep(philo->time_to.time_to_eat);
		pthread_mutex_unlock(&philo->right->mutex);
		pthread_mutex_unlock(&philo->left->mutex);
		philo->left->fork_available = TRUE;
		philo->right->fork_available = TRUE;
		gettimeofday(&end, NULL);
		printf("%f N.%d has been putting a fork\n", time_diff(&start, &end), philo->number);
	}
	else
		printf("\033[0;31m%f N.%d is died\033[0m\n", time_diff(&start, &end), philo->number);
}

void	is_sleep(struct timeval start, t_philo *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	printf("%f N.%d is sleeping\n",time_diff(&start, &end), philo->number);
	usleep(philo->time_to.time_to_sleep);
}

void	is_think(struct timeval start, t_philo *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	printf("%f N.%d is thinking\n",time_diff(&start, &end), philo->number);
	while(1)
		if (philo->left->fork_available == TRUE 
			&& philo->right->fork_available == TRUE)
			break ;
	return ;
}
