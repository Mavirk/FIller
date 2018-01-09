/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:46:18 by rmurdoch          #+#    #+#             */
/*   Updated: 2018/01/09 11:46:28 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		space_check(int overlap, char **piece, t_vars mdim, t_vars pdim)
{
	int		flag;
	int		x;
	int		y;

	x = 0;
	flag = 0;
	if (overlap != 1)
		return (0);
	while (x < pdim.ht && flag == 0)
	{
		y = 0;
		while (y < pdim.wt && flag == 0)
		{
			if (piece[x][y] == '*' &&
				((mdim.x + x) >= mdim.ht || (mdim.y + y) >= mdim.wt + 1))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		is_valid(char **map, char **piece, t_vars mdim, t_vars pdim)
{
	int overlap;

	overlap = 0;
	while (pdim.x < pdim.ht && overlap <= 1)
	{
		pdim.y = 0;
		while (pdim.y < pdim.wt && overlap <= 1)
		{
			if ((piece[pdim.x][pdim.y] == '*') &&
				((mdim.x + pdim.x) >= 0 && (mdim.x + pdim.x + 1) < mdim.ht) &&
				((mdim.y + pdim.y) >= 0 && (mdim.y + pdim.y) < mdim.wt))
			{
				if (map[mdim.x + pdim.x][mdim.y + pdim.y] == ft_toupper(pdim.hy)
					|| map[mdim.x + pdim.x][mdim.y + pdim.y] == pdim.hy)
					return (-1);
				if (map[mdim.x + pdim.x][mdim.y + pdim.y] == ft_toupper(pdim.hx)
					|| map[mdim.x + pdim.x][mdim.y + pdim.y] == pdim.hx)
					overlap++;
			}
			pdim.y++;
		}
		pdim.x++;
	}
	return (space_check(overlap, piece, mdim, pdim));
}

int		print_output(int x, int y, int flag)
{
	if (flag > 0)
	{
		ft_putnbr(x);
		ft_putstr(" ");
		ft_putnbr(y);
		ft_putendl("");
		return (1);
	}
	return (0);
}

int		check_move(char **map, char **piece, t_vars mdim, t_vars pdim)
{
	int		flag;

	flag = 0;
	pdim.x = 0;
	pdim.y = 0;
	mdim.x = 0;
	while (mdim.x < mdim.ht && flag == 0)
	{
		mdim.y = 0;
		while (mdim.x < mdim.ht && mdim.y < mdim.wt && flag == 0)
		{
			if (is_valid(map, piece, mdim, pdim) == 1)
			{
				if (mdim.hx <= mdim.x || mdim.hy <= mdim.y)
				{
					mdim.hx = mdim.x;
					mdim.hy = mdim.y;
				}
				flag++;
			}
			mdim.y++;
		}
		mdim.x++;
	}
	return (print_output(mdim.hx, mdim.hy, flag));
}

int		main(void)
{
	char	**map;
	char	**piece;
	t_vars	mdim;
	t_vars	pdim;

	get_player(&pdim.hx, &pdim.hy);
	get_input(&mdim.ht, &mdim.wt);
	map = get_map(mdim.ht, mdim.wt);
	get_input(&pdim.ht, &pdim.wt);
	piece = get_piece(pdim.ht, pdim.wt);
	while (check_move(map, piece, mdim, pdim) == 1)
	{
		get_input(&mdim.ht, &mdim.wt);
		map = get_map(mdim.ht, mdim.wt);
		get_input(&pdim.ht, &pdim.wt);
		piece = get_piece(pdim.ht, pdim.wt);
	}
	print_output(999, 999, 1);
	return (0);
}
