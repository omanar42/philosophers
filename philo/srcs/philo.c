/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:05:33 by omanar            #+#    #+#             */
/*   Updated: 2022/06/06 22:15:07 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosophers(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->data->nb_of_phs)
	{
		pthread_create(&ph[i].th, NULL, &simulation, &ph[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < ph->data->nb_of_phs)
	{
		pthread_create(&ph[i].th, NULL, &simulation, &ph[i]);
		i += 2;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*ph;

	if ((ac != 5 && ac != 6) || checker(av))
		return (printf("Invalid Arguments\n"));
	data = (t_data *)malloc(sizeof(t_data));
	ph = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!ph || !data)
		return (printf("Error: Cannot allocate memory\n"));
	parsing(data, ac, av);
	preparing(data, ph);
	philosophers(ph);
	while (1)
	{
		data->full = 0;
		if (shinigami(ph))
			return (0);
	}
	return (0);
}
