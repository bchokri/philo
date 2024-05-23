/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:18:49 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/14 16:57:46 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char option)
{
	pthread_mutex_t	pritn_mutex;

	pthread_mutex_init(&pritn_mutex, NULL);
	pthread_mutex_lock(&pritn_mutex);
	if (option == 'f')
		printf("%ld ms philo %d take a fork 1\n", get_time('m')
			- philo->start_s, philo->philo_id + 1);
	else if (option == 'F')
		printf("%ld ms philo %d take a fork 2\n", get_time('m')
			- philo->start_s, philo->philo_id + 1);
	else if (option == 'e')
		printf("%ld ms philo %d is eating now %ld time\n", get_time('m')
			- philo->start_s, philo->philo_id + 1, philo->nb_meals + 1);
	else if (option == 's')
		printf("%ld ms philo %d is sleeping now\n", get_time('m')
			- philo->start_s, philo->philo_id + 1);
	else if (option == 't')
		printf("%ld ms philo %d is thinking now\n", get_time('m')
			- philo->start_s, philo->philo_id + 1);
	else if (option == 'd')
		printf("%ld ms philo %d is deid\n", get_time('m')
			- philo->start_s, philo->philo_id + 1);
	if (option != 'd')
		pthread_mutex_unlock(&pritn_mutex);
}
