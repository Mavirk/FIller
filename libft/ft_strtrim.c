/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:28:46 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/10/01 18:23:43 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	while (ft_isspace((char)s[len - 1]))
		len--;
	while (ft_isspace(*(char*)s))
	{
		len--;
		s++;
	}
	if (len <= 0)
		len = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = -1;
	while (++i < len)
		str[i] = (char)s[i];
	return (str);
}
