/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:31 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 21:45:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	static_set_pos(const char *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (i);
		++i;
	}
	return (0);
}

static int			static_check_set(const char *set)
{
	int	i;
	int	i2;

	i = 0;
	while (set[i])
	{
		if (!ft_strin(ALPHABET, set[i]) && !ft_strin(ALPHABET_CAP, set[i])
		&& !ft_strin(DEC, set[i]))
			return (0);
		++i;
	}
	i = 0;
	while (set[i])
	{
		i2 = i + 1;
		while (set[i2])
			if (set[i] == set[i2++])
				return (0);
		++i;
	}
	if (i < 2)
		return (0);
	return (1);
}

long long			ft_atoibase(const char *set, const char *str)
{
	long long	nbr;
	size_t		base;
	int			sign;

	if (!set || !str || !static_check_set(set))
		return (0);
	base = ft_strlen(set);
	sign = 1;
	nbr = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && ft_strin(set, *str))
	{
		nbr = (LL)(nbr * base + static_set_pos(set, *str));
		++str;
	}
	return (sign * nbr);
}

unsigned long long	ft_atouibase(const char *set, const char *str)
{
	unsigned long long	nbr;
	size_t				base;

	if (!set || !str || !static_check_set(set))
		return (0);
	base = ft_strlen(set);
	nbr = 0;
	while (*str && ft_strin(set, *str))
	{
		nbr = nbr * base + static_set_pos(set, *str);
		++str;
	}
	return (nbr);
}

unsigned long long	ft_antouibase(const char *set, const char *str,
					long long len)
{
	unsigned long long	nbr;
	size_t				base;
	long long			i;

	if (!set || !str || !static_check_set(set))
		return (0);
	base = ft_strlen(set);
	nbr = 0;
	i = 0;
	while (str[i] && ft_strin(set, str[i]) && (len == -1 || i < len))
	{
		nbr = nbr * base + static_set_pos(set, str[i]);
		++i;
	}
	return (nbr);
}
