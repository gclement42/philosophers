/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:43:14 by gclement          #+#    #+#             */
/*   Updated: 2023/04/28 14:23:20 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum s_state
{
	EAT,
	THINK,
	SLEEP
}	t_state;

typedef struct s_time_to
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_time_to;

typedef struct s_philo
{
	int				number;
	t_time_to		time_to;
	t_state			state;
}	t_philo;

#endif