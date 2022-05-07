/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:42:32 by saozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:35:06 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdarg.h>
# include <limits.h>

# define EATING 2
# define THINKING 3
# define SLEEPING 4
# define DEATH 5
# define FORK_LEFT 6
# define FORK_RIGHT 7
# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		*left_hand;
	pthread_mutex_t		*right_hand;
	pthread_mutex_t		*display_message_mutex;
	pthread_t			philo_thread;
	struct s_total_data	*total_data;
	unsigned long long	death_time;
	int					is_there_left_fork;
	int					is_there_right_fork;
	int					eat_times;
}	t_philo;

typedef struct s_total_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death_check_mutex;
	pthread_mutex_t	*death_situation_change_mutex;
	t_philo			*philos;
	int				total_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times_for_each_philosopher;
	int				*forks_available;
	int				ac;
	int				death_check;
}	t_total_data;

void				display_message(t_philo *data, int position);
int					ft_atoi(char *s);
unsigned long long	get_time_from_func(void);
void				exit_free_function(t_total_data *total_data);
void				mutex_data_add(t_total_data *total_data);
void				philo_data_add(int ac, char **av, t_total_data *total_data);
void				*philosophers(void *data);
void				ft_sleep(unsigned long long usec, t_philo *philo);
int					death_check(t_philo *philo);
void				forks_check_to_use(t_philo *philo);
void				forks_check_to_release(t_philo *philo);

#endif