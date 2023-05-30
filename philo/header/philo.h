/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:39:25 by gclement          #+#    #+#             */
/*   Updated: 2023/05/16 14:20:10 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* thread */
pthread_t	*create_all_thread(
				int number_of_philosophers, t_philo *philosophers);
pthread_t	create_thread(t_philo *philo);
void		wait_thread(pthread_t *thread_id, t_philo *philosophers, int nb);

/* Philosopher */
t_philo		create_philosopher(t_time_to time_to, struct timeval time_start, int nb);
t_philo		*create_all_philosophers(
				int number_of_philosophers, t_time_to time_to);
void		*philosopher_routine(void *data);

/* Action*/

void		is_eat(struct timeval start, t_philo *philo);
void		is_sleep(struct timeval start, t_philo *philo);
void		is_think(struct timeval start, t_philo *philo);
void		is_dying(t_philo *philo);

void		check_if_die(t_philo *philosophers \
		, pthread_t *thread_id, int number_of_philosophers);

/* Utils */
int			ft_atoi(char *str);
long		time_diff(struct timeval *start);

#endif
