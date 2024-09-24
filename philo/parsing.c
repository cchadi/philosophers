/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:03:48 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/22 16:05:56 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_global	*new(void)
{
	t_global	*new;

	new = malloc(sizeof(t_global));
	if (!new)
		return (NULL);
	new->n_philo = 0;
	new->nbr_to_eat = -1;
	new->t_die = 0;
	new->t_sleep = 0;
	new->is_dead = 0;
	new->nbr_eating = 1;
	return (new);
}

t_global	*parsing(char **av)
{
	int			i;
	int			nbr;
	t_global	*global;

	global = new();
	i = 1;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if (nbr != -1 && nbr >= 0 && i <= 5)
			i++;
		else
			return (write(1, "Invalid\n", 9), free(global), NULL);
	}
	global->n_philo = ft_atoi(av[1]);
	global->t_die = ft_atoi(av[2]);
	global->t_eat = ft_atoi(av[3]);
	global->t_sleep = ft_atoi(av[4]);
	if (av[5])
		global->nbr_to_eat = ft_atoi(av[5]);
	global->start = get_current();
	pthread_mutex_init(&global->eat_flag, NULL);
	pthread_mutex_init(&global->dead_flag, NULL);
	return (global);
}
