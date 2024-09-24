/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:39 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/24 19:17:39 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->next->chopstick);
		pthread_mutex_lock(&p->chopstick);
	}
	else
	{
		pthread_mutex_lock(&p->chopstick);
		pthread_mutex_lock(&p->next->chopstick);
	}
}

void	unlock_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->chopstick);
	pthread_mutex_unlock(&p->next->chopstick);
}

int	to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead_flag);
	if (philo->philo_eat == -2
		|| philo->info->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->info->dead_flag);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead_flag);
	if (print_msg(philo, "is sleeping") == 1)
		return (1);
	ft_sleep(philo, philo->info->t_sleep);
	if (print_msg(philo, "is thinking") == 1)
		return (1);
	return (0);
}

int	to_eat(t_philo *p)
{
	if (is_dead(p) == 0 && p->philo_eat != -2 && eating_times(p) == 0)
	{
		lock_forks(p);
		print_msg(p, "has taken fork");
		print_msg(p, "has taken fork");
		print_msg(p, "is eating");
		if (is_dead(p))
			return (1);
		pthread_mutex_lock(&p->info->eat_flag);
		p->last_eat = get_current();
		pthread_mutex_unlock(&p->info->eat_flag);
		ft_sleep(p, p->info->t_eat);
		unlock_forks(p);
		pthread_mutex_lock(&p->info->eat_flag);
		p->philo_eat++;
		pthread_mutex_unlock(&p->info->eat_flag);
		eating_times(p);
		return (0);
	}
	else
	{
		return (1);
	}
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(250);
	while (1)
	{
		if (to_eat(philo) == 1)
			break ;
		if (to_sleep(philo) == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}
