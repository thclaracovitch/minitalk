/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:30:15 by thclarac          #+#    #+#             */
/*   Updated: 2023/08/31 11:30:17 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tempd;
	char	*temps;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tempd = (char *)dest;
	temps = (char *)src;
	while (i < n)
	{
		tempd[i] = temps[i];
		i++;
	}
	return (dest);
}
