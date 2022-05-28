/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:04:43 by omanar            #+#    #+#             */
/*   Updated: 2022/05/28 18:54:13 by omanar           ###   ########.fr       */
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
	int				nb_of_phs;
	int				nb_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	long			start_time;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	message;
}	t_data;

typedef struct s_philo {
	int			id;
	int			dead;
	long		start_time;
	long		last_meal_time;
	int			left_fork;
	int			right_fork;
	pthread_t	th;
	t_data		*data;
}	t_philo;

int		ft_atoi(const char *str);
int		checker(char **av);
void	parsing(t_data *data, t_philo *ph, int ac, char **av);
void	philosophers(t_philo *ph);
void	*simulation(void *arg);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);
void	died(t_philo *ph);
long	get_time(long start);
void	ft_usleep(long usec);
void	printer(t_philo *ph, char *str);
int		shinigami(t_philo *ph);

#endif