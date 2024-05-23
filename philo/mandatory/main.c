/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:15:07 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/14 16:55:38 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_program(t_data *data)
{
	free(data->t);
	free(data->forks);
}

static int	condition_to_break1(t_data *data)
{
	int	i;

	i = 0;
	if (data->nbr_l_meals != -1 && data->nbr_philos
		* data->nbr_l_meals == data->nbr_count_meals)
	{
		while (i < data->nbr_philos)
		{
			pthread_mutex_destroy(&data->philos->forks[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

static int	condition_to_break2(t_data *data, long time_now)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->nbr_philos)
	{
		if (time_now - data->philos[i].time_lst_meal > data->time_die)
		{
			print_msg(&data->philos[i], 'd');
			while (j < data->nbr_philos)
			{
				pthread_mutex_destroy(&data->philos->forks[i]);
				j++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

static int	keep_thread_alive(t_data *data)
{
	struct timeval	c_t;
	long			time_now;

	while (1)
	{
		gettimeofday(&c_t, NULL);
		time_now = (c_t.tv_usec / 1000) + c_t.tv_sec * 1000;
		if (condition_to_break1(data) == 0)
		{
			clean_program(data);
			return (0);
		}
		if (condition_to_break2(data, time_now) == 0)
		{
			clean_program(data);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;

	if ((ac == 5 || ac == 6) && check_argument(av) == 0)
	{
		initialize_data(&data, av, ac);
		philos = initialize_philo(&data);
		data.philos = philos;
		create_mutex(&data, philos);
		create_threads(&data);
		return (keep_thread_alive(&data));
	}
	else
	{
		printf("Wrong input try with another\n");
		return (1);
	}
	return (0);
}
