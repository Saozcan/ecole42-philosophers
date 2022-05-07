/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:29:07 by saozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:36:51 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	arg_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			exit(1);
		i++;
	}
}

int	ft_atoi(char *s)
{
	long long	return_nbr;

	return_nbr = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			exit(1);
		s++;
	}
	arg_check(s);
	while (*s >= '0' && *s <= '9')
	{
		return_nbr = ((return_nbr * 10) + (*(s++) - 48));
		if (return_nbr > INT_MAX)
			exit (1);
	}
	return (return_nbr);
}
