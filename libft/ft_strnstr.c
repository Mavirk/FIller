/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:54:28 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 11:49:36 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;

	if (*little == '\0')
		return ((char *)big);
	len_l = ft_strlen(little);
	while (*big && len >= len_l)
	{
		if (*big == *little && ft_memcmp(big, little, len_l) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
