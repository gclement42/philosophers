/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:43:14 by gclement          #+#    #+#             */
/*   Updated: 2023/05/11 13:41:21 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"
# include <pthread.h>
# include <sys/time.h>

typedef enum s_state
{
	EAT,
	THINK,
	SLEEP
}	t_state;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_time_to
{
	int	die;
	int	eat;
	int	sleep;
	int	nb_times_must_eat;
}	t_time_to;

typedef struct s_fork
{
	t_bool					available;
	pthread_mutex_t			mutex;
}	t_fork;

typedef struct s_philo
{
	struct timeval			time_start;
	pthread_t				id;
	pthread_mutex_t			mutex;
	int						number;
	t_fork					fork;
	t_time_to				time_to;
	int						count_eat;
	struct timeval			last_meal;
	t_fork					*fork_right;
	t_bool					is_dead;
	t_bool					stop;
}	t_philo;

#endif