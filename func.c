/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 03:15:24 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 06:42:23 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pa(t_env *tmp, t_env *b, t_list *env)
{
	while (b)
	{
		env->pa++;
		push(&tmp, &b);
		if (b && env->v != 1)
			ft_putstr("pa ");
		else
			ft_putstr("pa");
		if (env->v == 1)
			print_v(tmp, b);
	}
}

void	print_sa(t_env *tmp, t_env *b, t_env *a, t_list *env)
{
	env->sa++;
	ft_putstr("sa");
	swap(&tmp);
	if (env->v == 1)
		print_v(tmp, b);
	if (!ft_verif(tmp, a) && (!b))
	{
		if (env->v == 0)
			ft_putchar('\n');
		if (env->d == 1)
		{
			ft_putchar('\n');
			print_d(env);
		}
		if (env->n == 1)
			print_n(env);
		exit(0);
	}
}

void	print_ra(t_env **tmp, t_env *b, t_list *env)
{
	env->ra++;
	ft_putstr("ra");
	rotate(&(*tmp));
	if (env->v == 1)
		print_v((*tmp), b);
}

void	print_rra(t_env **tmp, t_env *b, t_env *a, t_list *env)
{
	env->rra++;
	ft_putstr("rra");
	rotate_reverse(&(*tmp));
	if (env->v == 1)
		print_v((*tmp), b);
	if (!ft_verif((*tmp), a) && (!b))
	{
		if (env->v == 0)
			ft_putchar('\n');
		if (env->d == 1)
		{
			ft_putchar('\n');
			print_d(env);
		}
		if (env->n == 1)
			print_n(env);
		exit(0);
	}
}

void	print_d(t_list *env)
{
	ft_putstr("sa : ");
	ft_putnbr(env->sa);
	ft_putstr(" - ");
	ft_putstr("pa : ");
	ft_putnbr(env->pa);
	ft_putstr(" - ");
	ft_putstr("pb : ");
	ft_putnbr(env->pb);
	ft_putstr(" - ");
	ft_putstr("ra : ");
	ft_putnbr(env->ra);
	ft_putstr(" - ");
	ft_putstr("rra : ");
	ft_putnbr(env->rra);
	ft_putchar('\n');
}
