/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:04:27 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/31 18:15:36 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_memdel(void **memptr)
{
	if (memptr != NULL && *memptr != NULL)
	{
		free(*memptr);
		*memptr = NULL;
	}
}
