/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:41:18 by omanar            #+#    #+#             */
/*   Updated: 2022/05/28 18:50:56 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->mutex[ph->left_fork]);
	printer(ph, "has taken a fork\n");
	pthread_mutex_lock(&ph->data->mutex[ph->right_fork]);
	printer(ph, "has taken a fork\n");
	printer(ph, "is eating\n");
	ph->last_meal_time = get_time(ph->data->start_time);
	ft_usleep(ph->data->time_to_eat * 1000);
	pthread_mutex_unlock(&ph->data->mutex[ph->left_fork]);
	pthread_mutex_unlock(&ph->data->mutex[ph->right_fork]);
}

void	sleeping(t_philo *ph)
{
	printer(ph, "is sleeping\n");
	ft_usleep(ph->data->time_to_sleep * 1000);
}

void	thinking(t_philo *ph)
{
	printer(ph, "is thinking\n");
}

void	died(t_philo *ph)
{
	printer(ph, "died\n");
}

void	*simulation(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}
