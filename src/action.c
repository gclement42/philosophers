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

void	eat(float timestamp,t_philo *philo)
{
	if (philo->left->fork_available == TRUE
		&& philo->right->fork_available == TRUE)
	{
		philo->left->fork_available = FALSE;
		philo->right->fork_available = FALSE;
		pthread_mutex_lock(&philo->right->mutex);
		pthread_mutex_lock(&philo->left->mutex);
		philo->state = EAT;
		printf("%f N.%d is eating\n", timestamp, philo->number);
	}
}
