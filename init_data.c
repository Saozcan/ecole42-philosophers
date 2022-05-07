/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:33:03 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/28 16:29:51 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_data_add_2(t_total_data *total_data, pthread_mutex_t *tmp)
{
	int	i;

	i = -1;
	while (++i < total_data->total_philosophers)
	{
		total_data->philos[i].id = i + 1;
		total_data->philos[i].display_message_mutex = tmp;
		total_data->philos[i].left_hand = &total_data->forks[i];
		total_data->philos[i].right_hand = &total_data->forks[(i + 1) % \
		total_data->total_philosophers];
		total_data->philos[i].is_there_left_fork = FALSE;
		total_data->philos[i].is_there_right_fork = FALSE;
		total_data->philos[i].eat_times = 0;
		total_data->philos[i].total_data = total_data;
	}
}

void	mutex_data_add(t_total_data *total_data)
{
	int				i;
	pthread_mutex_t	*tmp_display_message;

	tmp_display_message = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	total_data->death_check_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	total_data->death_situation_change_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	total_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	total_data->total_philosophers);
	pthread_mutex_init(total_data->death_check_mutex, NULL);
	pthread_mutex_init(tmp_display_message, NULL);
	pthread_mutex_init(total_data->death_situation_change_mutex, NULL);
	i = -1;
	while (++i < total_data->total_philosophers)
		pthread_mutex_init(&total_data->forks[i], NULL);
	mutex_data_add_2(total_data, tmp_display_message);
}

void	philo_data_add(int ac, char **av, t_total_data *total_data)
{
	int	i;

	if (!(ac == 5 || ac == 6))
	{
		free(total_data);
		exit(1);
	}
	total_data->forks_available = NULL;
	total_data->total_philosophers = ft_atoi(av[1]);
	total_data->forks_available = malloc(sizeof(int) * \
	total_data->total_philosophers);
	i = -1;
	while (++i < total_data->total_philosophers)
		total_data->forks_available[i] = 1;
	total_data->time_to_die = ft_atoi(av[2]);
	total_data->time_to_eat = ft_atoi(av[3]);
	total_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		total_data->eat_times_for_each_philosopher = ft_atoi(av[5]);
	total_data->philos = (t_philo *)malloc(sizeof(t_philo) * \
	total_data->total_philosophers);
	total_data->ac = ac;
	total_data->death_check = 0;
}
