/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:59 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/18 12:28:26 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_check(t_philo *p)
{
	printf("%ld %d is dead\n", (get_current() - p->info->start), p->id);
	pthread_mutex_lock(&p->info->dead_flag);
	p->info->is_dead = 1;
	pthread_mutex_unlock(&p->info->dead_flag);
}

int	checking(t_philo *philo)
{
	t_philo	*p;

	p = philo;
	while (1)
	{
		pthread_mutex_lock(&p->info->eat_flag);
		if ((get_current() - p->last_eat) > p->info->t_die)
		{
			dead_check(p);
			pthread_mutex_unlock(&p->info->eat_flag);
			break ;
		}
		pthread_mutex_lock(&p->info->dead_flag);
		if (p->info->nbr_eating == p->info->nbr_to_eat)
		{
			printf("nbr to eat was exceeded\n");
			pthread_mutex_unlock(&p->info->dead_flag);
			pthread_mutex_unlock(&p->info->eat_flag);
			break ;
		}
		pthread_mutex_unlock(&p->info->dead_flag);
		pthread_mutex_unlock(&p->info->eat_flag);
		p = p->next;
	}
	return (0);
}
