/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:09:47 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 11:47:41 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dlen;
	size_t	size;

	i = 0;
	dlen = 0;
	size = n;
	while (dest[dlen] && size-- != 0)
		dlen++;
	size = n - dlen;
	if (size == 0)
		return (dlen + ft_strlen(src));
	while (src[i] != '\0')
	{
		if (size != 1)
		{
			dest[dlen + i] = src[i];
			size--;
		}
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + i);
}
