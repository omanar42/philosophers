/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:04:43 by omanar            #+#    #+#             */
/*   Updated: 2022/05/10 19:51:21 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo {
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_philo;

typedef struct s_data {
	int	number_of_philosophers;
}	t_data;

int		ft_atoi(const char *str);
void	parsing(t_data *data, char **av);

#endif