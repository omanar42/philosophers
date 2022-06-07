/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:45:33 by omanar            #+#    #+#             */
/*   Updated: 2022/06/07 02:43:34 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_data {
	int		full;
	int		meals;
	int		nb_of_phs;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start_time;
	sem_t	*time;
	sem_t	*fork;
	sem_t	*message;
}	t_data;

typedef struct s_philo {
	int			id;
	int			meals;
	long		last_meal_time;
	pid_t		pid;
	pthread_t	th;
	t_data		*data;
}	t_philo;

int		ft_atoi(const char *str);
int		checker(char **av);
void	parsing(t_data *data, int ac, char **av);
void	preparing(t_data *data, t_philo *ph);
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