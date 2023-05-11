/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:22:35 by gclement          #+#    #+#             */
/*   Updated: 2023/05/11 11:16:50 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_diff(struct timeval *start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start->tv_sec) * 1000
		+ (end.tv_usec - start->tv_usec) / 1000);
}


