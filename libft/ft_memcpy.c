/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:27:17 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/15 14:37:23 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	const char	*srce;
	char		*dest;

	i = 0;
	srce = (const char *)src;
	dest = (char *)dst;
	while ((size_t)i < n)
	{
		*(dest + i) = *(srce + i);
		i++;
	}
	return (dest);
}
