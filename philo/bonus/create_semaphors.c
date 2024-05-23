/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_semaphors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:12:52 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/08 14:17:18 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphors(t_data *data, t_philo *philos)
{
	sem_t	*sem;
	sem_t	*pritn_sem;
	sem_t	*die;
	int		i;

	pritn_sem = sem_open("/sem_print", O_CREAT, 0644, 1);
	sem = sem_open("/sem_forks", O_CREAT, 0644, data->nbr_philos);
	die = sem_open("/sem_die", O_CREAT, 0644, 1);
	data->sem_die = die;
	sem_wait(data->sem_die);
	data->pritn_sem = pritn_sem;
	i = 0;
	data->forks = sem;
	while (i < data->nbr_philos)
	{
		philos[i].forks = sem;
		philos[i].pritn_sem = pritn_sem;
		i++;
	}
}
