/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:52:53 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 06:50:57 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	count(t_env *count, t_env *a, t_env *b, t_list *list)
{
	t_env	*tmp;
	int		i;
	int		nbtmp;

	i = 0;
	nbtmp = 0;
	tmp = count;
	nbtmp = tmp->elem;
	while (tmp)
	{
		if (nbtmp < tmp->elem)
			nbtmp = tmp->elem;
		if (count->prev_nb < tmp->elem && tmp->elem != nbtmp)
			count->prev_nb = tmp->elem;
		i++;
		tmp = tmp->next;
	}
	count->fatnb = nbtmp;
	count->big_nb = i;
	if (i > 3)
		ft_veriflast(count, a, b, &(*list));
}

void	ft_veriflast(t_env *count, t_env *a, t_env *b, t_list *list)
{
	t_env *tmp;

	tmp = count;
	while (tmp->next != NULL && tmp->elem <= tmp->next->elem)
		tmp = tmp->next;
	if (tmp->next->next == NULL &&
			tmp->elem == count->fatnb &&
			tmp->next->elem == count->prev_nb && count->big_nb > 3)
	{
		print_rra(&count, b, a, &(*list));
		if (list->v == 0)
			ft_putchar(' ');
		print_rra(&count, b, a, &(*list));
		if (list->v == 0)
			ft_putchar(' ');
		print_sa(&(*count), b, a, &(*list));
		if (list->v == 0)
			ft_putchar(' ');
		print_ra(&count, b, &(*list));
		if (list->v == 0)
			ft_putchar(' ');
		print_ra(&count, b, &(*list));
	}
}

void	print_end(t_list list)
{
	if (list.v == 0)
		ft_putchar('\n');
	if (list.d == 1)
	{
		ft_putchar('\n');
		print_d(&list);
	}
	if (list.n == 1)
		print_n(&list);
}

int		while_para(t_list **list, char **argv, int i)
{
	while (argv[(*list)->i][i])
	{
		if (argv[(*list)->i][i] == '-')
			break ;
		if (argv[(*list)->i][i] == 'd')
			(*list)->d = 1;
		if (argv[(*list)->i][i] == 'v')
			(*list)->v = 1;
		if (argv[(*list)->i][i] == 'n')
			(*list)->n = 1;
		if (argv[(*list)->i][i] >= '0' && argv[(*list)->i][i] <= '9')
			break ;
		if (argv[(*list)->i][i] != 'd' && argv[(*list)->i][i] != 'v' &&
				argv[(*list)->i][i] != 'n' && argv[(*list)->i][i] != '\0')
			error_negative();
		i++;
	}
	return (i);
}
