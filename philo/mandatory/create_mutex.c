/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:25:49 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 21:14:10 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutex(t_data *data, t_philo *philos)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = take_forks(data);
	data->forks = forks;
	i = 0;
	while (i < data->nbr_philos)
	{
		philos[i].forks = forks;
		i++;
	}
}
