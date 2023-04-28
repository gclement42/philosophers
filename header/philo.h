/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:39:25 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 14:01:09 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

/* thread */
pthread_t	*create_all_thread(int number_of_philosophers, t_time_to time_to);
pthread_t	create_thread(t_philo *philo);
void		wait_thread(pthread_t *thread_id, int nb);

/* Philosopher */
t_philo		create_philosopher(t_time_to time_to, int nb);
void		*philosopher_routine(void *data);

int			ft_atoi(char *str);

#endif
