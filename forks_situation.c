/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:46:16 by saozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:16:33 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	forks_check_to_use(t_philo *philo)
{
	while ((!philo->is_there_left_fork || !philo->is_there_right_fork))
	{
		if (death_check(philo))
			break ;
		pthread_mutex_lock(philo->left_hand);
		if (!philo->is_there_left_fork && \
		philo->total_data->forks_available[philo->id - 1])
		{
			philo->is_there_left_fork = TRUE;
			philo->total_data->forks_available[philo->id - 1] = 0;
			display_message(philo, FORK_LEFT);
		}
		pthread_mutex_unlock(philo->left_hand);
		pthread_mutex_lock(philo->right_hand);
		if (!philo->is_there_right_fork && philo->total_data->\
		forks_available[philo->id % philo->total_data->total_philosophers])
		{
			philo->is_there_right_fork = TRUE;
			philo->total_data->forks_available[philo->id % \
			philo->total_data->total_philosophers] = 0;
			display_message(philo, FORK_RIGHT);
		}
		pthread_mutex_unlock(philo->right_hand);
	}
}

void	forks_check_to_release(t_philo *philo)
{
	pthread_mutex_lock(philo->total_data->death_check_mutex);
	if (philo->total_data->death_check == 1)
	{
		pthread_mutex_unlock(philo->total_data->death_check_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->total_data->death_check_mutex);
	pthread_mutex_lock(philo->left_hand);
	pthread_mutex_lock(philo->right_hand);
	philo->is_there_left_fork = FALSE;
	philo->total_data->forks_available[philo->id - 1] = 1;
	philo->is_there_right_fork = FALSE;
	philo->total_data->forks_available[philo->id % \
	philo->total_data->total_philosophers] = 1;
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
}
