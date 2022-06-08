/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:41:18 by omanar            #+#    #+#             */
/*   Updated: 2022/06/08 00:03:11 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	eating(t_philo *ph)
{
	sem_wait(ph->data->fork);
	printer(ph, "has taken a fork\n", get_time(ph->data->start_time));
	sem_wait(ph->data->fork);
	printer(ph, "has taken a fork\n", get_time(ph->data->start_time));
	printer(ph, "is eating\n", get_time(ph->data->start_time));
	ph->meals++;
	ph->last_meal_time = get_time(ph->data->start_time);
	ft_usleep(ph->data->time_to_eat * 1000);
	sem_post(ph->data->fork);
	sem_post(ph->data->fork);
	if (ph->meals == ph->data->meals)
		exit(0);
}

void	sleeping(t_philo *ph)
{
	printer(ph, "is sleeping\n", get_time(ph->data->start_time));
	ft_usleep(ph->data->time_to_sleep * 1000);
}

void	thinking(t_philo *ph)
{
	printer(ph, "is thinking\n", get_time(ph->data->start_time));
}

void	died(t_philo *ph)
{
	sem_wait(ph->data->message);
	printf("%ld ms : Philosopher %d deid\n",
		get_time(ph->data->start_time), ph->id);
	exit(1);
}

void	simulation(t_philo *ph)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, &shinigami, ph) != 0)
	{
		printf("Error: pthread failed to be created\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
}
