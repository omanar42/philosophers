/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:43:12 by omanar            #+#    #+#             */
/*   Updated: 2022/06/10 16:18:26 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

void	printer(t_philo *ph, char *str, long time)
{
	sem_wait(ph->data->output);
	printf("%ld ms : Philosopher %d %s", time, ph->id, str);
	sem_post(ph->data->output);
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
	data->start_time = get_time(0);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_OUTPUT);
	data->fork = sem_open(SEM_FORK, O_CREAT, 0664, data->nb_of_phs);
	data->output = sem_open(SEM_OUTPUT, O_CREAT, 0664, 1);
	if (data->fork == SEM_FAILED || data->output == SEM_FAILED)
	{
		printf("Error: Semaphore Failed\n");
		exit(EXIT_FAILURE);
	}
}

void	preparing(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_of_phs)
	{
		ph[i].id = i + 1;
		ph[i].meals = 0;
		ph[i].last_meal_time = 0;
		ph[i].data = data;
		i++;
	}
}

void	*shinigami(void *arg)
{
	t_philo	*ph;
	long	time;

	ph = (t_philo *)arg;
	while (1)
	{
		time = get_time(ph->data->start_time + ph->last_meal_time);
		if (time >= ph->data->time_to_die)
			died(ph);
	}
	return (NULL);
}
