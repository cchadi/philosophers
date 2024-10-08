/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:04:16 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/24 19:18:18 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	get_current(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else
		perror("gettimeofday");
	return (-1);
}

void	ft_sleep(t_philo *p, int t)
{
	long	time;

	(void)p;
	time = get_current();
	while (time + t > get_current() && !is_dead(p))
	{
		usleep(100);
	}
}

int	is_dead(t_philo *p)
{
	pthread_mutex_lock(&p->info->dead_flag);
	if (p->info->is_dead == 1)
	{
		pthread_mutex_unlock(&p->info->dead_flag);
		return (1);
	}
	pthread_mutex_unlock(&p->info->dead_flag);
	return (0);
}

int	print_msg(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->info->dead_flag);
	if (p->info->is_dead == 0 && p->info->nbr_eating != p->info->n_philo)
	{
		printf("%ld %d %s\n", (get_current() - p->info->start), p->id, msg);
		pthread_mutex_unlock(&p->info->dead_flag);
		return (0);
	}
	pthread_mutex_unlock(&p->info->dead_flag);
	return (1);
}

int	eating_times(t_philo *p)
{
	pthread_mutex_lock(&p->info->eat_flag);
	if (p->info->nbr_to_eat != -1 && p->philo_eat != -2
		&& p->philo_eat == p->info->nbr_to_eat)
	{
		p->philo_eat = -2;
		p->info->nbr_eating++;
		pthread_mutex_unlock(&p->info->eat_flag);
		return (1);
	}
	pthread_mutex_unlock(&p->info->eat_flag);
	return (0);
}
