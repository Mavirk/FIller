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

#include "../header/filler.h"

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
