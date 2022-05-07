/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:45:13 by saozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:08:19 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	death_check(t_philo *philo)
{
	if (get_time_from_func() >= philo->death_time)
	{
		display_message(philo, DEATH);
		return (1);
	}
	return (0);
}
