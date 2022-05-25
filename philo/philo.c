/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:05:33 by omanar            #+#    #+#             */
/*   Updated: 2022/05/25 02:06:50 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->data->mutex);
	printf("000 ms : Philosopher %d has taken a fork\n", ph->id);
	printf("000 ms : Philosopher %d is eating\n", ph->id);
	pthread_mutex_unlock(&ph->data->mutex);
	usleep(ph->data->time_to_eat);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->mutex);
	printf("000 ms : Philosopher %d is sleeping\n", ph->id);
	pthread_mutex_lock(&ph->data->mutex);
	usleep(ph->data->time_to_sleep);
}

void	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->mutex);
	printf("000 ms : Philosopher %d is thinking\n", ph->id);
	pthread_mutex_lock(&ph->data->mutex);
}

void	died(t_philo *ph)
{
	printf("000 ms : Philosopher %d died\n", ph->id);
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
	pthread_mutex_t *mutex;

	data->nb_of_phs = ft_atoi(av[1]);
	data->nb_of_forks = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_eat = ft_atoi(av[5]);
	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_phs);
	while (i < data->nb_of_phs)
	{
		ph[i].id = i;
		pthread_mutex_init(&mutex[i], NULL);
		ph[i].start_time = 0;
		ph[i].left_fork = &mutex[i];
		ph[i].right_fork = &mutex[i + 1];
		ph[i].data = data;
		i++;
	}
}

void	*simulation(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

void philosophers(t_philo *ph)
{
	int i;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		pthread_create(&ph[i].philo, NULL, &simulation, (void *)&ph[i]);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo *ph;

	if ((ac != 5 && ac != 6) || checker(av))
		return (printf("Invalid Arguments\n"));
	ph = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!ph)
		return (printf("Error: Aloccation Failed\n"));
	parsing(&data, ph, ac, av);
	philosophers(ph);
	while(1);
	return (0);
}
