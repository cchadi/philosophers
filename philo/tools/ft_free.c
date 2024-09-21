/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:02:35 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/21 20:40:56 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_free(t_philo *philo)
{
	t_philo	*head;
	t_philo	*tmp;
	int		flag;

	flag = 1;
	head = philo;
	while (philo != head || flag == 1)
	{
		flag = 0;
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
}
