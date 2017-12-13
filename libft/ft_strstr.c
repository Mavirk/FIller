/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:16:39 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 11:51:28 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len_l;

	if (*little == '\0')
		return ((char *)big);
	len_l = ft_strlen(little);
	while (*big)
	{
		if (*big == *little && ft_memcmp(big, little, len_l) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
