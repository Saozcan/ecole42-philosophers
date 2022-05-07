/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:41:35 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/28 16:29:18 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_threads(t_total_data *total_data)
{
	int	i;

	i = 0;
	while (i < total_data->total_philosophers)
	{
		total_data->philos[i].death_time = get_time_from_func() + \
		total_data->time_to_die;
		pthread_create(&total_data->philos[i].philo_thread, NULL, \
		philosophers, (void *)&total_data->philos[i]);
		i += 2;
	}
	i = 1;
	usleep(15000);
	while (i < total_data->total_philosophers)
	{
		total_data->philos[i].death_time = get_time_from_func() + \
		total_data->time_to_die;
		pthread_create(&total_data->philos[i].philo_thread, NULL, \
		philosophers, (void *)&total_data->philos[i]);
		i += 2;
	}
}

void	arg_check_for_five(char **av)
{
	if (ft_atoi(av[1]) == 0 || \
		ft_atoi(av[2]) == 0 || \
		ft_atoi(av[3]) == 0 || \
		ft_atoi(av[4]) == 0)
		exit(0);
}

void	arg_check_for_six(char **av)
{
	if (ft_atoi(av[1]) == 0 || \
		ft_atoi(av[2]) == 0 || \
		ft_atoi(av[3]) == 0 || \
		ft_atoi(av[4]) == 0 || \
		ft_atoi(av[5]) == 0)
		exit(0);
}

int	main(int ac, char **av)
{
	int				i;
	t_total_data	*total_data;

	if (ac == 5)
		arg_check_for_five(av);
	else if (ac == 6)
		arg_check_for_six(av);
	else
		return (0);
	total_data = (t_total_data *)malloc(sizeof(t_total_data));
	philo_data_add(ac, av, total_data);
	mutex_data_add(total_data);
	create_threads(total_data);
	i = -1;
	while (++i < total_data->total_philosophers)
		pthread_join(total_data->philos[i].philo_thread, NULL);
	exit_free_function(total_data);
	return (0);
}
