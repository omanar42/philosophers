/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:40:13 by omanar            #+#    #+#             */
/*   Updated: 2022/05/28 18:42:50 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(long start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void ft_usleep(long usec)
{
	long time;

	time = get_time(0);
	while (get_time(time) * 1000 < usec)
		usleep(100);
}

void printer(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->data->message);
	printf("%ld ms : Philosopher %d %s", get_time(ph->data->start_time), ph->id, str);
	pthread_mutex_lock(&ph->data->message);
}
