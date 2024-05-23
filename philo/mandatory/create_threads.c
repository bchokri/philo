/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:26:46 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 20:48:20 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *data)
{
	int	i;

	data->t = malloc(sizeof(pthread_t) * data->nbr_philos);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].thread = data->t[i];
		pthread_create(&data->philos[i].thread, NULL, routine,
			&data->philos[i]);
		usleep(100);
		i++;
	}
}
