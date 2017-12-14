/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:40:32 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/12/14 17:01:27 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	read_line(char **sv, int *rsize, char **t, int fd)
{
	while (!ft_strchr(*sv, '\n') && *rsize > 0)
	{
		*t = ft_strdup(*sv);
		if (*sv)
			free(*sv);
		*sv = (char *)ft_memalloc(BUFF_SIZE + ft_strlen(*t) + 1);
		ft_strcpy(*sv, *t);
		*rsize = read(fd, (*sv + ft_strlen(*t)), BUFF_SIZE);
		*(*sv + ft_strlen(*t) + *rsize) = '\0';
		free(*t);
	}
}

int		chk_sv(char **sv, char **t, char ***line)
{
	char *t2;

	if (ft_strchr(*sv, '\n'))
	{
		*t = ft_strchr(*sv, '\n') + 1;
		*(ft_strchr(*sv, '\n')) = '\0';
		**line = ft_strdup(*sv);
		if (**t != '\0')
		{
			t2 = *sv;
			*sv = ft_strdup(*t);
			ft_strdel(&t2);
		}
		else
		{
			ft_strdel(sv);
			return (0);
		}
	}
	return (1);
}

int		reset(char **sv, char **t, char ***line, int *rsize)
{
	if (chk_sv(sv, t, line) && **sv && !(ft_strchr(*sv, '\n')) && *rsize == 0)
	{
		**line = ft_strdup(*sv);
		ft_strdel(sv);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *sv = NULL;
	char		*t;
	int			rsize;

	rsize = 1;
	if (!sv)
	{
		sv = (char *)ft_memalloc(BUFF_SIZE + 1);
		if (fd < 0 || (rsize = read(fd, sv, BUFF_SIZE)) == -1)
		{
			ft_strdel(&sv);
			return (-1);
		}
		sv[rsize] = '\0';
		if (rsize == 0)
		{
			ft_strdel(&sv);
			*line = NULL;
			return (0);
		}
	}
	read_line(&sv, &rsize, &t, fd);
	return (reset(&sv, &t, &line, &rsize));
}
