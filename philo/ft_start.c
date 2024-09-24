/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:56 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/23 18:39:00 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_philo *philo)
{
	t_philo	*head;
	t_philo	*tmp;
	int		flag;

	flag = 0;
	tmp = philo;
	head = philo;
	while ((head != tmp) || flag == 0)
	{
		flag = 1;
		pthread_join(head->philo, NULL);
		head = head->next;
	}
}

void	create_threads(t_philo *philo)
{
	pthread_t		checker;
	t_philo			*head;
	t_philo			*tmp;
	int				flag;

	if (!philo)
		return ;
	flag = 1;
	tmp = philo;
	head = philo;
	while ((head != tmp) || flag == 1)
	{
		flag = 0;
		pthread_create(&head->philo, NULL, (void *)&routine, head);
		head = head->next;
	}
	pthread_create(&checker, NULL, (void *)&checking, philo);
	join_threads(philo);
	pthread_join(checker, NULL);
	return ;
}

void	ft_start(t_global *g)
{
	t_philo	*head;

	if (!g)
		return ;
	head = linked_list(g);
	create_threads(head);
	ft_free(head);
	free(g);
}
