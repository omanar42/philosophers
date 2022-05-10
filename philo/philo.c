/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:05:33 by omanar            #+#    #+#             */
/*   Updated: 2022/05/10 20:07:49 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	checker(char **av)
{
	
}

void	parsing(t_data *data, char **av)
{
	data->number_of_philosophers = ft_atoi(av[1]);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		checker(av);
		parsing(&data, av);
	}
	return (0);
}
