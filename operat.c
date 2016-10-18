/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 00:39:11 by ale-floc          #+#    #+#             */
/*   Updated: 2015/02/07 08:20:33 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_env **list)
{
	int elem;

	if ((*list)->next != NULL)
	{
		elem = (*list)->elem;
		(*list)->elem = (*list)->next->elem;
		(*list)->next->elem = elem;
	}
}

void	push(t_env **first, t_env **second)
{
	if ((*second) != NULL)
	{
		size_push_front(&(*first), (*second)->elem);
		free(*second);
		(*second) = (*second)->next;
	}
}

void	rotate(t_env **list)
{
	if ((*list)->next != NULL)
	{
		size_push_back(&(*list), (*list)->elem);
		(*list) = (*list)->next;
	}
}

void	rotate_reverse(t_env **list)
{
	t_env *new;

	new = *list;
	if (new->next != NULL)
	{
		while (new->next != NULL)
			new = new->next;
		size_push_front(list, new->elem);
		del_last(list);
	}
}
