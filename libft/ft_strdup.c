/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:47:37 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 11:46:22 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*strstart;

	str = (char *)malloc(sizeof(char) * ((int)ft_strlen(s1) + 1));
	strstart = str;
	if (!s1 || !str)
		return (NULL);
	ft_strcpy(str, s1);
	return (strstart);
}
