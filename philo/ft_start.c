/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:56 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/18 12:32:20 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	detach_threads(t_philo *philo)
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
		pthread_detach(head->philo);
		head = head->next;
	}
}

void	create_threads(t_philo *philo)
{
	t_philo	*checker;
	t_philo	*head;
	t_philo	*tmp;
	int		flag;

	flag = 1;
	tmp = philo;
	head = philo;
	while ((head != tmp) || flag == 1)
	{
		flag = 0;
		pthread_create(&head->philo, NULL, (void *)&routine, head);
		usleep(3);
		head = head->next;
	}
	detach_threads(philo);
	head = philo;
	checker = lst_new(NULL, -5);
	pthread_create(&checker->philo, NULL, (void *)&checking, head);
	pthread_join(checker->philo, NULL);
	return ;
}

void	ft_start(t_global *g)
{
	t_philo	*head;

	if (!g)
		return ;
	head = linked_list(g);
	create_threads(head);
}
