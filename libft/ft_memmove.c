/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:30:40 by thclarac          #+#    #+#             */
/*   Updated: 2023/08/31 11:30:41 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temps;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temps = (char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = temps[i];
			i++;
		}
	}
	else
	{
		n--;
		while (n + 1 > 0)
		{
			((char *)dest)[n] = temps[n];
			n--;
		}
	}
	return (dest);
}
