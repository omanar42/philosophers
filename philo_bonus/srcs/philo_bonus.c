/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:48:12 by omanar            #+#    #+#             */
/*   Updated: 2022/06/07 02:34:40 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	finish_all(t_philo *ph)
{
	int	i;
	int	status;

	status = 0;
	while (!status)
		if (waitpid(-1, &status, 0) == -1)
			break ;
	i = -1;
	while (++i < ph->data->nb_of_phs)
		kill(ph[i].pid, SIGKILL);
}

void	philosophers(t_philo *ph)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		pid = fork();
		if (pid == -1)
		{
			printf("Error: Failed to fork child process\n");
			exit(EXIT_FAILURE);
		}
		else if (pid != 0)
			ph[i].pid = pid;
		if (pid == 0)
			simulation(&ph[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*ph;
	t_data	*data;

	if ((ac != 5 && ac != 6) || checker(av))
		return (printf("Invalid Arguments\n"));
	data = (t_data *)malloc(sizeof(t_data));
	ph = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!ph || !data)
		return (printf("Error: Aloccation Failed\n"));
	parsing(data, ac, av);
	preparing(data, ph);
	philosophers(ph);
	finish_all(ph);
	sem_close(data->time);
	sem_close(data->fork);
	sem_close(data->message);
	return (0);
}
