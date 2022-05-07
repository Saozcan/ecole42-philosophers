/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:26:59 by saozcan           #+#    #+#             */
/*   Updated: 2022/04/26 05:39:18 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(unsigned long long nbr)
{
	unsigned long long	i;

	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-1 * nbr);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	ft_printf(char *s, ...)
{
	va_list	var_list;

	va_start(var_list, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == 'i' || *(s + 1) == 'd')
				ft_putnbr(va_arg(var_list, unsigned long long));
			else if (*(s + 1) == 's')
				ft_putstr(va_arg(var_list, char *));
			else if (*(s + 1) == 'c')
				ft_putchar(va_arg(var_list, int));
			else
				ft_putchar(*(s + 1));
			s++;
		}
		else
			ft_putchar(*s);
		s++;
	}
	va_end(var_list);
}

void	display_message(t_philo *data, int position)
{
	static int	i = 1;

	pthread_mutex_lock(data->display_message_mutex);
	if (i == 1)
	{
		if (position == EATING)
			ft_printf("%d %d is eating\n", get_time_from_func(), data->id);
		else if (position == SLEEPING)
			ft_printf("%d %d is sleeping\n", get_time_from_func(), data->id);
		else if (position == THINKING)
			ft_printf("%d %d is thinking\n", get_time_from_func(), data->id);
		else if (position == FORK_LEFT || position == FORK_RIGHT)
			ft_printf("%d %d has taken a fork\n", \
			get_time_from_func(), data->id);
		else if (position == DEATH)
		{
			ft_printf("%d %d died\n", get_time_from_func(), data->id);
			i = 0;
			pthread_mutex_lock(data->total_data->death_check_mutex);
			data->total_data->death_check = 1;
			pthread_mutex_unlock(data->total_data->death_check_mutex);
		}
	}
	pthread_mutex_unlock(data->display_message_mutex);
}
