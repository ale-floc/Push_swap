/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 23:06:53 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 19:25:25 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	int				elem;
	int				v;
	int				fatnb;
	int				big_nb;
	int				prev_nb;
	struct s_env	*next;
}				t_env;

typedef struct	s_list
{
	int			i;
	int			v;
	int			d;
	int			n;
	int			sa;
	int			pa;
	int			pb;
	int			ra;
	int			rra;
	int			small;
}				t_list;

t_env			*size_create_elem(int elem);
void			size_push_front(t_env **e, int elem);
void			size_push_back(t_env **e, int elem);
void			del_last(t_env **list);
void			print_end(t_list list);
void			ft_veriflast(t_env *count, t_env *a, t_env *b, t_list *list);
void			count(t_env *count, t_env *a, t_env *b, t_list *list);
void			swap(t_env **e);
void			push(t_env **first, t_env **second);
void			rotate(t_env **list);
void			rotate_reverse(t_env **list);
void			ft_print(t_env *a);
void			print_v(t_env *a, t_env *b);
void			print_d(t_list *env);
void			print_n(t_list *list);
void			parametre(t_list **list, char **argv);
void			init_option(int argc, char **argv, t_list *list, t_env **a);
void			main_while(t_env **tmp, t_env **a, t_env **b, t_list *list);
void			same_nb(t_env *a, int nb);
void			print_pa(t_env *tmp, t_env *b, t_list *env);
void			print_sa(t_env *tmp, t_env *b, t_env *a, t_list *env);
void			print_ra(t_env **tmp, t_env *b, t_list *env);
void			print_rra(t_env **tmp, t_env *b, t_env *a, t_list *env);
void			exit_error(char *str);
void			error_negative(void);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr(int nbr);
void			create_list(t_list *list, t_env **a, char **argv, int i);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *str);
int				ft_strequ(char const *s1, char const *s2);
int				while_para(t_list **list, char **argv, int i);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi_letter(const char *str);
int				ft_verif(t_env *tmp, t_env *a);
int				ft_small_nb(t_env *tmp);
int				ft_check(t_env *tmp, int i);

#endif
