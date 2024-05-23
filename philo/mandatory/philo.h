/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:15:23 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 21:18:59 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					philo_id;
	long				start_s;
	long				time_lst_meal;
	pthread_t			thread;
	int					left_fork;
	int					right_fork;
	long				nb_meals;
	t_data				*data;
	pthread_mutex_t		*forks;
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
	pthread_t			*t;
	pthread_mutex_t		*forks;
}						t_data;

int						check_argument(char **av);
int						ft_atoi(char *str);
size_t					ft_strlen(char *str);
long					get_time(char option);
void					print_msg(t_philo *philo, char option);
void					*routine(void *data_arg);
pthread_mutex_t			*take_forks(t_data *data);
t_philo					*initialize_philo(t_data *data);
void					initialize_data(t_data *data, char **av, int ac);
void					create_mutex(t_data *data, t_philo *philos);
void					create_threads(t_data *data);

#endif