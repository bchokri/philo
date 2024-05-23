/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:39:15 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/08 14:42:11 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		kill(data->philos[i].id_p, SIGKILL);
		i++;
	}
}
