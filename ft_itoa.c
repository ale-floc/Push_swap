/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:10:12 by ale-floc          #+#    #+#             */
/*   Updated: 2015/03/10 06:52:08 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_counter(int nb)
{
	int counter;

	if (nb > 0)
		counter = 1;
	else
		counter = 2;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		i;
	int		o;
	char	*str;

	o = 0;
	i = ft_counter(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	str[i--] = '\0';
	if (n < 0)
		o = 1;
	while (i >= 0)
	{
		if (o == 0)
			str[i--] = ((n % 10) + '0');
		if (o == 1)
			str[i--] = (-(n % 10) + '0');
		n = n / 10;
	}
	if (o == 1)
		str[0] = '-';
	return (str);
}

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (ft_strlen((char *)s1) == ft_strlen((char *)s2))
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
