/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:39 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/18 12:47:07 by csaidi           ###   ########.fr       */
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

void	to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead_flag);
	if (philo->philo_eat == philo->info->nbr_to_eat
		|| philo->info->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->info->dead_flag);
		return ;
	}
	pthread_mutex_unlock(&philo->info->dead_flag);
	print_msg(philo, "is sleeping");
	ft_sleep(philo, philo->info->t_sleep);
	print_msg(philo, "is thinking");
	usleep(10);
}

void	to_eat(t_philo *p)
{
	if (is_dead(p) == 0 && p->philo_eat != -2 && eating_times(p) == 0)
	{
		lock_forks(p);
		print_msg(p, "has taken  fork");
		print_msg(p, "has taken  fork");
		print_msg(p, "is eating");
		pthread_mutex_lock(&p->info->eat_flag);
		p->last_eat = get_current();
		pthread_mutex_unlock(&p->info->eat_flag);
		ft_sleep(p, p->info->t_eat);
		unlock_forks(p);
		pthread_mutex_lock(&p->info->eat_flag);
		p->philo_eat++;
		pthread_mutex_unlock(&p->info->eat_flag);
	}
	else
	{
		pthread_mutex_lock(&p->info->dead_flag);
		p->info->is_dead = 1;
		pthread_mutex_unlock(&p->info->dead_flag);
		return ;
	}
}

void	*routine(t_philo *philo)
{
	while (1)
	{
		to_eat(philo);
		to_sleep(philo);
	}
	return (NULL);
}
