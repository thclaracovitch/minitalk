/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:36:16 by thclarac          #+#    #+#             */
/*   Updated: 2023/08/31 11:36:18 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		temp = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			temp = (char *)big + i;
			if (little[j + 1] == '\0')
				return (temp);
			j++;
		}
		i++;
	}
	return (NULL);
}
