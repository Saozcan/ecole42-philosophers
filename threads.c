/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:38:07 by saozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:19:34 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_sleeping(t_philo *philo)
{
	display_message(philo, SLEEPING);
	ft_sleep(philo->total_data->time_to_sleep, philo);
}

void	philosopher_eating(t_philo *philo)
{	
	forks_check_to_use(philo);
	philo->eat_times++;
	philo->death_time = get_time_from_func() + philo->total_data->time_to_die;
	display_message(philo, EATING);
	ft_sleep(philo->total_data->time_to_eat, philo);
	forks_check_to_release(philo);
}

void	limited_dinner(t_philo *philo)
{
	if (philo->total_data->eat_times_for_each_philosopher == 0)
		exit_free_function(philo->total_data);
	while (philo->eat_times < philo->total_data->eat_times_for_each_philosopher)
	{
		pthread_mutex_lock(philo->total_data->death_check_mutex);
		if (philo->total_data->death_check == 1)
		{
			pthread_mutex_unlock(philo->total_data->death_check_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->total_data->death_check_mutex);
		philosopher_eating(philo);
		philosopher_sleeping(philo);
		display_message(philo, THINKING);
	}
}

void	*philosophers(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->total_data->ac == 6)
		limited_dinner(philo);
	else
	{
		while (1)
		{
			pthread_mutex_lock(philo->total_data->death_check_mutex);
			if (philo->total_data->death_check == 1)
			{
				pthread_mutex_unlock(philo->total_data->death_check_mutex);
				break ;
			}
			pthread_mutex_unlock(philo->total_data->death_check_mutex);
			philosopher_eating(philo);
			philosopher_sleeping(philo);
			display_message(philo, THINKING);
		}
	}
	return (0);
}
