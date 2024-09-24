/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:02:35 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/23 18:39:52 by csaidi           ###   ########.fr       */
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
	while (head != philo || flag == 1)
	{
		flag = 0;
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
