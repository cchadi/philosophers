/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:04:13 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/18 12:22:02 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	*lst_new(t_global *g, int id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	new->id = id;
	new->philo_eat = 0;
	if (!g)
		new->info = NULL;
	else
		new->info = g;
	new->last_eat = get_current();
	pthread_mutex_init(&new->chopstick, NULL);
	new->next = NULL;
	return (new);
}

t_philo	*lst_last(t_philo *node)
{
	if (!node)
		return (NULL);
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	lst_addback(t_philo **head, t_philo *new)
{
	t_philo	*last;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = lst_last(*head);
	last->next = new;
}

void	add_nextback(t_philo **head)
{
	t_philo	*last;

	last = lst_last(*head);
	last->next = *head;
}

t_philo	*linked_list(t_global *g)
{
	t_philo	*head;
	t_philo	*new;
	int		i;

	head = NULL;
	i = 1;
	while (i <= g->n_philo)
	{
		new = lst_new(g, i);
		lst_addback(&head, new);
		i++;
	}
	add_nextback(&head);
	return (head);
}
