/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:43:12 by omanar            #+#    #+#             */
/*   Updated: 2022/05/28 18:45:26 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int shinigami(t_philo *ph)
{
	int i;

	i = 0;
	while (i < ph[0].data->nb_of_phs)
	{
		if (get_time(ph[i].data->start_time + ph[i].last_meal_time)  >= ph[i].data->time_to_die)
		{
			died(&ph[i]);
			return (1);		
		}
		i++;
	}
	return (0);
}

int	checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
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

void	parsing(t_data *data, t_philo *ph, int ac, char **av)
{
	int i;

	data->nb_of_phs = ft_atoi(av[1]);
	data->nb_of_forks = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_eat = ft_atoi(av[5]);
	else
		data->number_of_eat = -1;
	i = 0;
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_phs);
	while (i < data->nb_of_phs)
	{
		ph[i].id = i + 1;
		pthread_mutex_init(&data->mutex[i], NULL);
		ph[i].start_time = 0;
		ph[i].left_fork = i;
		ph[i].right_fork = i + 1;
		if(i == data->nb_of_phs - 1)
			ph[i].right_fork = 0;
		ph[i].data = data;
		i++;
	}
}

void	philosophers(t_philo *ph)
{
	int i;

	i = 0;
	ph->data->start_time = get_time(0);
	while (i < ph->data->nb_of_phs)
	{
		pthread_create(&ph[i].th, NULL, &simulation, (void *)&ph[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < ph->data->nb_of_phs)
	{
		pthread_create(&ph[i].th, NULL, &simulation, (void *)&ph[i]);
		i += 2;
	}
}
