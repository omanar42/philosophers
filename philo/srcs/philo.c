/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:05:33 by omanar            #+#    #+#             */
/*   Updated: 2022/05/29 21:42:34 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*ph;

	if ((ac != 5 && ac != 6) || checker(av))
		return (printf("Invalid Arguments\n"));
	data = (t_data *)malloc(sizeof(t_data));
	ph = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!ph || !data)
		return (printf("Error: Aloccation Failed\n"));
	parsing(data, ph, ac, av);
	philosophers(ph);
	while (1)
	{
		data->full = 0;
		if (shinigami(ph))
			return (0);
	}
	return (0);
}
