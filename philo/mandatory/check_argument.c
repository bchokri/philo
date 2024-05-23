/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:53:07 by bchokri           #+#    #+#             */
/*   Updated: 2024/05/03 15:06:47 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_number(char *str, int count)
{
	int	number;

	number = ft_atoi(str);
	if (number <= 0 || count > 11)
		return (1);
	return (0);
}

static int	help_to_check(char **av, int i, int j, int count)
{
	while (av[i])
	{
		count = 0;
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == ' '
			|| av[i][j] == '0')
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
			count++;
		}
		if (check_number(av[i], count) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_argument(char **av)
{
	int	i;
	int	count;
	int	j;

	j = 0;
	count = 0;
	i = 1;
	return (help_to_check(av, i, j, count));
}
