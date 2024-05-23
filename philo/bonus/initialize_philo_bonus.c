/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:11:21 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/14 16:36:20 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	philo_take(int i, t_data *data)
{
	t_philo	philo;

	philo.philo_id = i;
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
