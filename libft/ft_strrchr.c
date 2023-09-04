/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:36:37 by thclarac          #+#    #+#             */
/*   Updated: 2023/09/04 09:28:08 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	i = 0;
	a = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = i;
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	else if (a >= 0)
		return ((char *)(s + a));
	return (NULL);
}
