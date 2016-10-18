/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:43:59 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 07:14:51 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void create_list(t_list *list, t_env **a, char **argv, int i)
{
	same_nb((*a), ft_atoi_letter(argv[list->i]));
	if (ft_strequ(argv[i], ft_itoa(ft_atoi_letter(argv[i]))))
		size_push_back(&(*a), ft_atoi_letter(argv[list->i]));
	else if (ft_atoi_letter(argv[i]) == 0)
		size_push_back(&(*a), ft_atoi_letter(argv[list->i]));
	else
	{
		ft_putstr_fd("Error : Overflow", 2);
		ft_putstr_fd("\n", 2);
		exit(2);
	}
	list->i++;
}

void print_n(t_list *list)
{
	int final;

	final = 0;
	ft_putstr("Move : ");
	final = list->pb + list->pa + list->sa + list->ra + list->rra;
	ft_putnbr(final);
	ft_putchar('\n');
}
