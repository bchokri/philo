/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:43:47 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/08 16:12:42 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	work_while(t_philo *philo)
{
	int				i;
	struct timeval	c_t;

	i = 0;
	while (1)
	{
		sem_wait(philo->forks);
		print_msg(philo, 'f');
		sem_wait(philo->forks);
		print_msg(philo, 'F');
		print_msg(philo, 'e');
		usleep(philo->data->time_eat * 1000);
		gettimeofday(&c_t, NULL);
		philo->time_lst_meal = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
		i++;
		philo->nb_meals++;
		sem_post(philo->forks);
		sem_post(philo->forks);
		if (i == philo->data->nbr_l_meals)
			exit(0);
		print_msg(philo, 's');
		usleep(philo->data->time_sleep * 1000);
		print_msg(philo, 't');
	}
}

void	process(t_philo *philo, pid_t id)
{
	struct timeval	c_t;

	if (id == 0)
	{
		gettimeofday(&c_t, NULL);
		philo->start_s = ((c_t.tv_usec / 1000) + c_t.tv_sec * 1000);
		philo->time_lst_meal = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
		take_care(philo);
		work_while(philo);
	}
}
