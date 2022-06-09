/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:43:12 by omanar            #+#    #+#             */
/*   Updated: 2022/06/09 23:49:52 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0)
			return (1);
		if (av[i][0] == 0)
			return (1);
		j = 0;
		if ((av[i][0] == '+') && av[i][1])
			j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing(t_data *data, int ac, char **av)
{
	data->nb_of_phs = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
	data->full = 0;
	data->start_time = get_time(0);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->output, NULL);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_phs);
}

void	preparing(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_of_phs)
	{
		ph[i].meals = 0;
		ph[i].id = i + 1;
		ph[i].left_fork = i;
		ph[i].right_fork = i + 1;
		ph[i].last_meal_time = 0;
		ph[i].data = data;
		if (i == data->nb_of_phs - 1)
			ph[i].right_fork = 0;
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
}

int	shinigami(t_philo *ph)
{
	int		i;
	long	time;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		pthread_mutex_lock(&ph->data->time);
		time = get_time(ph[i].data->start_time + ph[i].last_meal_time);
		if (ph[i].meals >= ph[i].data->meals && ph[i].data->meals != -1)
			ph->data->full++;
		pthread_mutex_unlock(&ph->data->time);
		if (ph->data->full == ph->data->nb_of_phs && ph[i].data->meals != -1)
			return (1);
		if (time >= ph[i].data->time_to_die)
		{
			died(&ph[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
