/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:55:10 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/12 18:27:06 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*str1;
	const char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	while ((size_t)i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
	}
	return (0);
}
