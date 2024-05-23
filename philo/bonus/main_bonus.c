/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:16 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/14 16:47:50 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	first_work(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (waitpid(0, &status, 0))
	{
		if (status == 0)
			i++;
		if (status != 0)
		{
			kill_all_process(data);
			sem_post(data->sem_die);
			break ;
		}
		if (i == data->nbr_philos)
		{
			sem_post(data->sem_die);
			break ;
		}
	}
}

void	second_work(t_data *data, t_philo *philos)
{
	kill_all_process(data);
	free(philos);
	sem_close(data->forks);
	sem_close(data->pritn_sem);
	sem_close(data->sem_die);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_die");
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if ((ac == 5 || ac == 6) && check_argument(av) == 0)
	{
		sem_unlink("/sem_forks");
		sem_unlink("/sem_print");
		sem_unlink("/sem_die");
		initialize_data(&data, av, ac);
		philos = initialize_philo(&data);
		data.philos = philos;
		create_semaphors(&data, philos);
		create_process(&data);
		first_work(&data);
		sem_wait(data.sem_die);
		second_work(&data, philos);
	}
	else
	{
		printf("Wrong input try with another\n");
		return (1);
	}
	return (0);
}
