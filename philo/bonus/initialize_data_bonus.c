/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:26 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/06 18:10:39 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initialize_data(t_data *data, char **av, int ac)
{
	data->nbr_philos = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->nbr_count_meals = 0;
	if (ac == 6)
		data->nbr_l_meals = ft_atoi(av[5]);
	else
		data->nbr_l_meals = -1;
}
