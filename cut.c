/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 03:16:02 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 19:29:37 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_nb(t_env *a, int nb)
{
	t_env *tmp;

	tmp = a;
	while (tmp)
	{
		if (nb == tmp->elem)
		{
			ft_putstr_fd("Error detected : Duplicate number", 2);
			ft_putchar_fd('\n', 2);
			exit(2);
		}
		else
			tmp = tmp->next;
	}
}

void	error_negative(void)
{
	ft_putstr_fd("usage : ./push_swap [-dnv] [nb..nb..]", 2);
	ft_putchar_fd('\n', 2);
	exit (2);
}

void	parametre(t_list **list, char **argv)
{
	int i;
	int tmp;

	i = 0;
	if (argv[(*list)->i][i] == '-')
	{
		i++;
		i = while_para(&(*list), argv, i);
		if ((*list)->d == 1 || (*list)->v == 1 || (*list)->n == 1 ||
				argv[(*list)->i][i] == '-')
		{
			(*list)->i++;
			if (argv[(*list)->i] != NULL &&
					!ft_strncmp(argv[(*list)->i], "--", 3))
				(*list)->i++;
		}
	}
	tmp = (*list)->i;
	if (argv[tmp++] == NULL)
		error_negative();
}

void	init_option(int argc, char **argv, t_list *list, t_env **a)
{
	list->i = 1;
	list->v = 0;
	list->n = 0;
	list->rra = 0;
	list->pa = 0;
	list->pb = 0;
	list->ra = 0;
	list->sa = 0;
	list->small = 0;
	if (argc < 2)
		error_negative();
	parametre(&list, argv);
	while (argv[list->i])
		create_list(&(*list), &(*a), argv, list->i);
	if (!ft_verif((*a), (*a)))
	{
		ft_putstr("Everything is OK !");
		if (list->v == 1)
			ft_putchar('\n');
	}
}

void	main_while(t_env **tmp, t_env **a, t_env **b, t_list *list)
{
	while ((*tmp))
	{
		list->small = ft_small_nb((*tmp));
		while (list->small != (*tmp)->elem)
		{
			if (list->small == (*tmp)->next->elem)
				print_sa((*tmp), (*b), (*a), &(*list));
			else if (list->small == (ft_check((*tmp), list->small) &&
				(*tmp)->big_nb != 3))
				print_rra(&(*tmp), (*b), (*a), &(*list));
			else
				print_ra(&(*tmp), (*b), &(*list));
			if (list->v != 1)
				ft_putchar(' ');
		}
		if (!ft_verif((*tmp), (*a)))
			break ;
		list->pb++;
		ft_putstr("pb");
		push(&(*b), &(*tmp));
		if (list->v == 1)
			print_v((*tmp), (*b));
		else
			ft_putchar(' ');
	}
}
