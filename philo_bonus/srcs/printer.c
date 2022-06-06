/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:40:13 by omanar            #+#    #+#             */
/*   Updated: 2022/06/06 16:51:33 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long	get_time(long start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	ft_usleep(long usec)
{
	long	time;

	time = get_time(0);
	while (get_time(time) * 1000 < usec)
		usleep(100);
}

void	printer(t_philo *ph, char *str, long time)
{
	sem_wait(ph->data->message);
	printf("%ld ms : Philosopher %d %s", time, ph->id, str);
	sem_post(ph->data->message);
}
