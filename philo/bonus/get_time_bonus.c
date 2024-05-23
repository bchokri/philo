/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:35:21 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/06 18:11:10 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(char option)
{
	struct timeval	c_t;
	long			time;

	time = 0;
	gettimeofday(&c_t, NULL);
	if (option == 'm')
		time = ((c_t.tv_sec * 1000) + (c_t.tv_usec / 1000));
	return (time);
}
