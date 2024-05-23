/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:43 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/14 16:35:59 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					philo_id;
	long				start_s;
	long				time_lst_meal;
	pid_t				id_p;
	long				nb_meals;
	t_data				*data;
	sem_t				*forks;
	sem_t				*pritn_sem;
}						t_philo;

typedef struct s_data
{
	long				nbr_philos;
	long				time_eat;
	long				time_sleep;
	long				time_die;
	long				nbr_l_meals;
	long				nbr_count_meals;
	t_philo				*philos;
	sem_t				*pritn_sem;
	sem_t				*forks;
	sem_t				*sem_die;
}						t_data;

int						check_argument(char **av);
int						ft_atoi(char *str);
void					initialize_data(t_data *data, char **av, int ac);
t_philo					*initialize_philo(t_data *data);
void					create_semaphors(t_data *data, t_philo *philos);
long					get_time(char option);
void					print_msg(t_philo *philo, char option);
void					create_process(t_data *data);
void					kill_all_process(t_data *data);
void					process(t_philo *philo, pid_t id);
void					take_care(t_philo *philo);

#endif