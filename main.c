/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 23:14:45 by ale-floc          #+#    #+#             */
/*   Updated: 2015/02/22 03:18:16 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_env	*size_create_elem(int elem)
{
	t_env *new;

	new = (t_env *)malloc(sizeof(t_env));
	new->elem = elem;
	new->next = NULL;
	return (new);
}

void	size_push_back(t_env **e, int elem)
{
	t_env *new;

	new = *e;
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = size_create_elem(elem);
	}
	else
		*e = size_create_elem(elem);
}

void	size_push_front(t_env **e, int elem)
{
	t_env *new;

	new = NULL;
	if (*e)
	{
		new = size_create_elem(elem);
		new->next = *e;
		*e = new;
	}
	else
		*e = size_create_elem(elem);
}

void	del_last(t_env **list)
{
	t_env *prev;
	t_env *tmp;

	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	prev = tmp;
	tmp = *list;
	while (tmp->next != prev)
		tmp = tmp->next;
	tmp->next = NULL;
	free(prev);
}

int		main(int argc, char **argv)
{
	t_list	list;
	t_env	*a;
	t_env	*b;
	t_env	*tmp;

	a = NULL;
	b = NULL;
	init_option(argc, argv, &list, &a);
	tmp = a;
	if (list.v == 1)
	{
		ft_putstr("Start");
		print_v(tmp, b);
	}
	if (ft_verif(tmp, a))
		count(&(*tmp), a, b, &list);
	main_while(&tmp, &a, &b, &list);
	print_pa(tmp, b, &list);
	print_end(list);
	return (0);
}
