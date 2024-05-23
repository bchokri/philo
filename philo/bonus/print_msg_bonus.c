/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:36:36 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/07 18:30:15 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_msg(t_philo *philo, char option)
{
	sem_wait(philo->pritn_sem);
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
	sem_post(philo->pritn_sem);
}
