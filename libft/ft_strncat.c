/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:21:14 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 11:49:11 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ps1;
	char	*ps2;
	size_t	i;

	i = 0;
	ps1 = (char*)s1;
	ps2 = (char*)s2;
	while (*ps1)
		ps1++;
	while (i < n && *ps2)
	{
		*ps1++ = *ps2++;
		i++;
	}
	*ps1 = '\0';
	return (s1);
}
