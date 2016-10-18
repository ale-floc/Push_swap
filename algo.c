/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:32:48 by ale-floc          #+#    #+#             */
/*   Updated: 2015/02/22 00:18:51 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_verif(t_env *tmp, t_env *a)
{
	while (tmp->next != NULL && tmp->elem <= tmp->next->elem)
		tmp = tmp->next;
	if (!tmp->next)
		return (0);
	else
		tmp = a;
	return (1);
}

int		ft_small_nb(t_env *tmp)
{
	int nb;

	nb = tmp->elem;
	while (tmp)
	{
		if (nb > tmp->elem)
			nb = tmp->elem;
		tmp = tmp->next;
	}
	return (nb);
}

int		ft_check(t_env *tmp, int i)
{
	t_env *last;

	last = tmp;
	while (last->next)
		last = last->next;
	if (i == last->elem)
		return (i);
	else
		return (0);
}

void	print_v(t_env *a, t_env *b)
{
	ft_putstr("->");
	ft_putchar('\n');
	ft_putstr("Liste a : ");
	if (a)
		ft_print(a);
	ft_putchar('\n');
	ft_putstr("Liste b :");
	if (b)
	{
		ft_putchar(' ');
		ft_print(b);
	}
	ft_putchar('\n');
}

void	ft_print(t_env *a)
{
	t_env *tmp;
	t_env *src;

	tmp = a;
	src = a;
	while (tmp->next)
		tmp = tmp->next;
	ft_putnbr(tmp->elem);
	while (tmp->elem != a->elem)
	{
		ft_putchar(' ');
		while (src->next != tmp)
			src = src->next;
		tmp = src;
		ft_putnbr(tmp->elem);
		src = a;
	}
}
