/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:43:44 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/26 04:40:52 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(unsigned long long usec, t_philo *philo)
{
	unsigned long long	start;

	start = get_time_from_func();
	while (get_time_from_func() - start < usec)
	{
		usleep(usec * 10);
		death_check(philo);
	}
}
