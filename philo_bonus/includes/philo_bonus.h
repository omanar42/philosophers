/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:45:33 by omanar            #+#    #+#             */
/*   Updated: 2022/06/06 16:51:36 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data {
	int				nb_of_phs;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	sem_t			*fork;
	sem_t			*message;
	sem_t			*time;
	int				meals;
	int				full;
	long			start_time;
}	t_data;

typedef struct s_philo {
	pid_t		pid;
	int			id;
	int			meals;
	int			start;
	int			is_eating;
	long		start_time;
	long		last_meal_time;
	int			left_fork;
	int			right_fork;
	pthread_t	th;
	t_data		*data;
}	t_philo;

int		ft_atoi(const char *str);
int		checker(char **av);
void	parsing(t_data *data, int ac, char **av);
void	parsing2(t_data *data, t_philo *ph);
void	philosophers(t_philo *ph);
void	simulation(t_philo *ph);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);
void	died(t_philo *ph);
long	get_time(long start);
void	ft_usleep(long usec);
void	printer(t_philo *ph, char *str, long time);
void	*shinigami(void *arg);

#endif