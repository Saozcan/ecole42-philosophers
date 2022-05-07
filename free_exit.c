/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:31:18 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/26 04:40:34 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_free_function(t_total_data *total_data)
{
	int	i;

	pthread_mutex_destroy(total_data->philos->display_message_mutex);
	free(total_data->philos->display_message_mutex);
	i = -1;
	while (++i < total_data->total_philosophers)
		pthread_mutex_destroy(&total_data->forks[i]);
	free(total_data->forks);
	free(total_data->philos);
	free(total_data->forks_available);
	pthread_mutex_destroy(total_data->death_check_mutex);
	pthread_mutex_destroy(total_data->death_situation_change_mutex);
	free(total_data->death_situation_change_mutex);
	free(total_data->death_check_mutex);
	free(total_data);
	exit(1);
}
