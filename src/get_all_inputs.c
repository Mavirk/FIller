/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:04:35 by rmurdoch          #+#    #+#             */
/*   Updated: 2018/01/09 12:04:43 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	get_player(int *hx, int *hy)
{
	char	*line;
	int		p;

	p = 111;
	get_next_line(0, &line);
	p = (ft_strsplit((const char *)line, ' ')[2][1] == '1') ? 111 : 120;
	free(line);
	if (p == 111)
	{
		*hx = 111;
		*hy = 120;
	}
	if (p == 120)
	{
		*hx = 120;
		*hy = 111;
	}
}

void	get_input(int *x, int *y)
{
	char	*line;

	get_next_line(0, &line);
	*x = ft_atoi(ft_strsplit((const char *)line, ' ')[1]);
	*y = ft_atoi(ft_strsplit((const char *)line, ' ')[2]);
	free(line);
}

char	**get_map(int x, int y)
{
	char	**map;
	char	*line;
	int		cx;

	cx = 0;
	map = (char**)malloc((sizeof(char*) * (x + 1)));
	get_next_line(0, &line);
	free(line);
	while (cx < x)
	{
		get_next_line(0, &line);
		map[cx] = (char*)malloc((sizeof(char) * (y + 1)));
		ft_strncpy(map[cx], ft_strsplit((const char *)line, ' ')[1], y + 1);
		cx++;
		free(line);
	}
	return (map);
}

char	**get_piece(int px, int py)
{
	char	**piece;
	char	*line;
	int		cx;

	cx = 0;
	piece = (char**)malloc((sizeof(char*) * (px + 1)));
	while (cx < px)
	{
		get_next_line(0, &line);
		piece[cx] = (char*)malloc((sizeof(char) * (py + 1)));
		ft_strcpy(piece[cx], line);
		cx++;
		ft_strdel(&line);
	}
	return (piece);
}
