/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:34:13 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/26 12:55:27 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time_from_func(void)
{
	struct timeval				take_time;
	static unsigned long long	start_time = 0;
	unsigned long long			ret;

	gettimeofday(&take_time, NULL);
	ret = take_time.tv_sec * 1000 + take_time.tv_usec / 1000;
	if (start_time == 0)
		start_time = ret;
	return (ret - start_time);
}
