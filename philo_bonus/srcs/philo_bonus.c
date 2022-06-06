/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:48:12 by omanar            #+#    #+#             */
/*   Updated: 2022/06/06 18:49:18 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	kill_them(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		kill(ph[i].pid, SIGKILL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*ph;
	int status;
	int res = 0;

	status = 0;
	if ((ac != 5 && ac != 6) || checker(av))
		return (printf("Invalid Arguments\n"));
	data = (t_data *)malloc(sizeof(t_data));
	ph = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!ph || !data)
		return (printf("Error: Aloccation Failed\n"));
	parsing(data, ac, av);
	parsing2(data, ph);
	philosophers(ph);
	while (res != -1 && status == 0) {
		res = waitpid(-1, &status, 0);
		// printf("status %d\n", status);
	}
	kill_them(ph);
	sem_close(data->time);
	sem_close(data->fork);
	sem_close(data->message);
	return (0);
}
