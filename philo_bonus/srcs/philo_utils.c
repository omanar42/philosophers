/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:43:12 by omanar            #+#    #+#             */
/*   Updated: 2022/06/05 20:57:10 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	is_enough(t_philo *ph)
{
	if (ph->meals == ph->data->meals)
		return (0);
	return (1);
}

void	*shinigami(void *arg)
{
	t_philo	*ph;
	long	time;

	ph = (t_philo *)arg;
	ph->data->start_time = get_time(0);
	while (1)
	{
		// if (ph->start == 1)
		// {
			sem_wait(ph->data->time);
			time = get_time(ph->data->start_time + ph->last_meal_time);
			sem_post(ph->data->time);
			if (time >= ph->data->time_to_die && ph->is_eating == 0)
				died(ph);
		// }
	}
	return (NULL);
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

void	parsing(t_data *data, int ac, char **av)
{
	data->nb_of_phs = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->start_time = get_time(0);
	data->time_to_sleep = ft_atoi(av[4]);
	data->full = 0;
	sem_unlink("fork");
	sem_unlink("message");
	sem_unlink("time");
	data->fork = sem_open("fork", O_CREAT, 0664, data->nb_of_phs);
	data->message = sem_open("message", O_CREAT, 0664, 1);
	data->time = sem_open("time", O_CREAT, 0664, 1);
	if (data->fork == SEM_FAILED || data->message == SEM_FAILED)
		perror("sem_open :");
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
}

void	parsing2(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_of_phs)
	{
		ph[i].start = 0;
		ph[i].is_eating = 1;
		ph[i].id = i + 1;
		ph[i].meals = 0;
		ph[i].start_time = 0;
		ph[i].last_meal_time = 0;
		ph[i].data = data;
		i++;
	}
}

void	philosophers(t_philo *ph)
{
	int	i;
	pid_t pid;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		pid = fork();
		if (pid != 0)
			ph[i].pid = pid;
		if (pid == 0)
			simulation(&ph[i]);
		i++;
	}
}
