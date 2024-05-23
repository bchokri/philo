/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:20:18 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/06 18:33:54 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stile_work(t_philo *philo, pthread_mutex_t eat_mutex)
{
	struct timeval	c_t;

	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
		print_msg(philo, 'f');
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		print_msg(philo, 'F');
		print_msg(philo, 'e');
		pthread_mutex_lock(&eat_mutex);
		philo->nb_meals++;
		gettimeofday(&c_t, NULL);
		philo->time_lst_meal = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
		philo->data->nbr_count_meals++;
		pthread_mutex_unlock(&eat_mutex);
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		print_msg(philo, 's');
		usleep(philo->data->time_sleep * 1000);
		print_msg(philo, 't');
	}
}

void	*routine(void *data_arg)
{
	t_philo			*philo;
	pthread_mutex_t	eat_mutex;

	philo = (t_philo *)data_arg;
	pthread_mutex_init(&eat_mutex, NULL);
	stile_work(philo, eat_mutex);
	return (NULL);
}
