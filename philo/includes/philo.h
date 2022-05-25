/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:04:43 by omanar            #+#    #+#             */
/*   Updated: 2022/05/24 21:33:13 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data {
	int	nb_of_phs;
	int	nb_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int number_of_eat;
	pthread_mutex_t mutex;
}	t_data;

typedef struct s_philo {
	int id;
	int dead;
	long long start_time;
	long long last_meal_time;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t philo;
	t_data *data;
}	t_philo;

int		ft_atoi(const char *str);
void	parsing(t_data *data, t_philo *ph, int ac, char **av);

#endif