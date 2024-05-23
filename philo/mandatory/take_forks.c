/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:21:43 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 15:08:05 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	take_fork(void)
{
	pthread_mutex_t	fork;

	pthread_mutex_init(&fork, NULL);
	return (fork);
}

pthread_mutex_t	*take_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (!forks)
		return (NULL);
	while (i < data->nbr_philos)
	{
		forks[i] = take_fork();
		i++;
	}
	return (forks);
}
