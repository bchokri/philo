/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:23:07 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 15:07:45 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	philo_take(int i, t_data *data)
{
	t_philo			philo;
	struct timeval	c_t;

	gettimeofday(&c_t, NULL);
	philo.philo_id = i;
	philo.start_s = ((c_t.tv_usec / 1000) + c_t.tv_sec * 1000);
	philo.time_lst_meal = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
	philo.left_fork = i;
	if (i == data->nbr_philos - 1)
		philo.right_fork = 0;
	else
		philo.right_fork = i + 1;
	philo.nb_meals = 0;
	philo.data = data;
	return (philo);
}

t_philo	*initialize_philo(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->nbr_philos);
	if (!philos)
		return (NULL);
	while (i < data->nbr_philos)
	{
		philos[i] = philo_take(i, data);
		i++;
	}
	return (philos);
}
