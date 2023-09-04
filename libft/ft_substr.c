/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:37:06 by thclarac          #+#    #+#             */
/*   Updated: 2023/08/31 11:37:09 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;
	size_t	len_r;

	len_s = ft_strlen(s);
	len_r = 0;
	if (start > len_s)
		len_r = 0;
	else if (start + len >= len_s)
		len_r = len_s - start;
	else
		len_r = len;
	i = 0;
	res = (char *)malloc((len_r + 1) * sizeof (*s));
	if (!res)
		return (NULL);
	while (i < len && start < len_s)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
