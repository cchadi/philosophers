/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:18 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/18 13:07:19 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	convert_ascii(const char *str, int i, int sign)
{
	long	n;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if (n > INT_MAX || n < INT_MIN)
			return (-1);
	}
	if (str[i])
		return (-1);
	return (n * sign);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	if (!str[0] || !str)
		return (0);
	while (str[i] == 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else
			return (0);
	}
	result = convert_ascii(str, i, sign);
	return ((long)result);
}
