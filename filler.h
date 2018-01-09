#ifndef FILLER_H
# define FILLER_H

#include <stdio.h>
#include "libft/libft.h"



typedef struct	s_vars
{
	int	wt;
	int	ht;
	int	x;
	int y;
	int hx;
	int hy;	
}				t_vars;

void 	get_player(int *hx, int *hy);
void	get_input(int *x, int *y);
char	**get_map(int x, int y);
char 	**get_piece(int px, int py);
int 	space_check(int overlap, char **piece, t_vars mdim, t_vars pdim);
int 	is_valid(char **map, char **piece, t_vars mdim, t_vars pdim);
int		print_output(int x, int y, int flag);
int 	check_move(char **map, char **piece, t_vars mdim, t_vars pdim);
#endif
