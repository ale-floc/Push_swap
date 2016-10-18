/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:59:31 by ale-floc          #+#    #+#             */
/*   Updated: 2015/02/12 15:44:28 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_letter(const char *str)
{
	long	o;
	int		i;
	int		k;

	i = 0;
	o = 0;
	k = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		o = (str[i] - '0') + (o * 10);
		i++;
	}
	if (str[i] != '\0')
		exit_error("Error detected : Letters\n");
	return (o * k);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(2);
}
