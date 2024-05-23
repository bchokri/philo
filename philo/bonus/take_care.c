/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_care.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:48:10 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/08 14:37:04 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*keep_attention(void *arg)
{
	t_philo			*philo;
	struct timeval	c_t;
	long			time_now;

	philo = (t_philo *)arg;
	while (1)
	{
		gettimeofday(&c_t, NULL);
		time_now = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
		if (time_now - philo->time_lst_meal > philo->data->time_die)
		{
			sem_wait(philo->pritn_sem);
			printf("%ld ms philo %d is died\n", get_time('m') - philo->start_s,
				philo->philo_id + 1);
			sem_post(philo->data->sem_die);
			exit(1);
		}
	}
	return (NULL);
}

void	take_care(t_philo *philo)
{
	pthread_t	t;

	pthread_create(&t, NULL, &keep_attention, philo);
}
