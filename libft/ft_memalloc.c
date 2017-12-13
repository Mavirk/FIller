/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:55:27 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/18 12:08:50 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	void	*i;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	i = mem;
	ft_memset(mem, 0, size);
	return (mem);
}
