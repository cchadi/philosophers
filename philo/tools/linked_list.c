#include "../philosophers.h"

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

t_philo *lst_new(t_global *g, int id)
{
    t_philo *new = malloc(1 * sizeof(t_philo));
    new->id = id;
    new->is_dead = 0;
    if (!g)
        new->info = NULL;
    else
        new->info = g;
    new->last_eat = 0;
    new->next = NULL;
    return (new);
}

void lst_addback(t_philo **head, t_philo *new)
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

void    add_nextback(t_philo **head)
{
    t_philo *last;

    last = lst_last(*head);
    last->next = *head;
}

t_philo *linked_list(t_global *g)
{
    t_philo *head;
    t_philo *new;
    int i;

    head = NULL;
    i = 0;
    while(i < g->n_philo)
    {
        new = lst_new(g, i);
        lst_addback(&head, new);
        i++;
    }
    add_nextback(&head);
    return (head);
}