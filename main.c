#include "filler.h"

void 	get_player(int *p)
{
	char	*line;

	get_next_line(0, &line);
	*p = (ft_strsplit((const char *)line, ' ')[2][1] == '1') ? 1 : 2;
	ft_strdel(&line);
}

void	get_input(int *x, int *y)
{
	char	*line;

	get_next_line(0, &line);
	*x = ft_atoi(ft_strsplit((const char *)line, ' ')[1]);
	*y = ft_atoi(ft_strsplit((const char *)line, ' ')[2]);
	ft_strdel(&line);
}

char	**get_map(int x)
{
	char	**map;
	char	*line;
	int 	cx;

	cx = -1;
	map = (char**)ft_memalloc(x + 1);
	map[x] = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (cx < (x - 1))
	{
		get_next_line(0, &line);
		map[++cx] = ft_strsplit((const char *)line, ' ')[1];
		ft_strdel(&line);
	}
	return(map);
}

char 	**get_piece(int px)
{
	char	**piece;
	char	*line;
	int 	cx;

	cx = -1;
	piece = (char**)ft_memalloc(px + 1);
	piece[px] = 0;
	while (cx < (px - 1))
	{
		cx++;
		get_next_line(0, &line);
		piece[cx] = ft_strdup(line);
		ft_strdel(&line);	
	}
	return(piece);
}

int 	is_valid(char **map, char **piece, t_vars mdim, t_vars pdim)
{
	while (pdim.x < pdim.ht)
	{
		pdim.y = 0;
		while (pdim.y < pdim.wt)
		{
			if (piece[pdim.x][pdim.y] == '*')
			{
				if (((mdim.x + pdim.x) >= 0 && (mdim.x + pdim.x) < mdim.ht) && 
					((mdim.y + pdim.y) >= 0 && (mdim.y + pdim.y) < mdim.wt))
				{	
					if (map[mdim.x + pdim.x][mdim.y + pdim.y] == 'X' || 
						map[mdim.x + pdim.x][mdim.y + pdim.y] == 'x')
						return (-1);	
					if (map[mdim.x + pdim.x][mdim.y + pdim.y] == 'O' || 
						map[mdim.x + pdim.x][mdim.y + pdim.y] == 'o')	
						return (1);
				}
			}
			pdim.y++;
		}
		pdim.x++;
	}
	return (0); 
}

int 	check_move(char **map, char **piece, t_vars mdim, t_vars pdim)
{
	pdim.x = 0;
	pdim.y = 0;
	while (mdim.x < mdim.ht)
	{
		mdim.y = 0;
		while (mdim.x < mdim.ht && mdim.y < mdim.wt)
		{
			if (is_valid(map, piece, mdim, pdim) == 1)
			{
				ft_putnbr(mdim.x);
				ft_putstr(" ");
				ft_putnbr(mdim.y);
				ft_putendl("");
				return(1);
			}
			mdim.y++;
		}
		mdim.x++;	
	}
	return (0);
}

// void	free_all(char**)

int		main(void)
{
	int 	p;
	char	**map;
	char 	**piece;
	t_vars	mdim;
	t_vars	pdim;

	get_player(&p);
	get_input(&mdim.ht, &mdim.wt);
	map = get_map(mdim.ht);
	get_input(&pdim.ht, &pdim.wt);
	piece = get_piece(pdim.ht);
	check_move (map, piece, mdim, pdim);

	get_input(&mdim.ht, &mdim.wt);
	map = get_map(mdim.ht);
	get_input(&pdim.ht, &pdim.wt);
	piece = get_piece(pdim.ht);
	check_move (map, piece, mdim, pdim);

	return(0);
}

	
	// ft_putendl("+++++++++++++++++++++++++++++++++++variables+++++++++++++++++++++++++++++++++++");
	// ft_putstr("mdim.ht :");
	// ft_putnbr(mdim.ht);
	// ft_putendl("");
	// ft_putstr("mdim.wt :");
	// ft_putnbr(mdim.wt);
	// ft_putendl("");
	// ft_putstr("mdim.x :");
	// ft_putnbr(mdim.x);
	// ft_putendl("");
	// ft_putstr("mdim.y :");
	// ft_putnbr(mdim.y);
	// ft_putendl("");
	// ft_putstr("pdim.ht :");
	// ft_putnbr(pdim.ht);
	// ft_putendl("");
	// ft_putstr("pdim.wt :");
	// ft_putnbr(pdim.wt);
	// ft_putendl("");
	// ft_putstr("pdim.x :");
	// ft_putnbr(pdim.x);
	// ft_putendl("");
	// ft_putstr("pdim.y :");
	// ft_putnbr(pdim.y);
	// ft_putendl("");	
	// ft_putchar(piece[0][0]);
	// ft_putchar(piece[0][1]);
	// ft_putendl("");
	// ft_putchar(piece[1][0]);
	// ft_putchar(piece[1][1]);
	// ft_putendl("");

	// ft_putendl("this is the map :");
	// int i = 0;
	// while (map[i])
	// {
	// 	ft_putendl(map[i]);
	// 	i++;
	// }
	// ft_putendl("this is a piece :");
	// i = 0;
	// while (piece[i])
	// {
	// 	ft_putendl(piece[i]);
	// 	i++;
	// }

// void 	get_move(char **map, int x, int y)
// {
// 	int     flag;
// 	int 	mx;
// 	int 	my;

// 	flag = 0;
// 	mx = 0;
// 	my = 0;
// 	while (flag == 0 && mx < x)
// 	{
// 		mx++;
// 		my = 0;
// 		while (flag == 0 && mx < x && my < y)
// 		{
// 			my++;
// 			if ((map[mx][my] == 'O' || map[mx][my] == 'o'))
// 				flag = 1;
// 		}				
// 	}
// }

	// ft_putendl("this is the map :");
	// i = 0;
	// while (map[i])
	// {
	// 	ft_putendl(map[i]);
	// 	i++;
	// }
	// ft_putendl("this is a piece :");
	// i = 0;
	// while (piece[i])
	// {
	// 	ft_putendl(piece[i]);
	// 	i++;
	// }
// void	check_move(char	**map, int x, int y)
// {	
// 	int 	cx;
// 	int 	cy;

// 	cx = 0;
// 	while (map[cx])
// 	{
// 		cy = 0;
// 		while (map[cx][cy])
// 		{
// 			if (map[cx][cy] == 'o' && )
// 			cy++;
// 		}
// 		cx++
// 	}
// }


	// char	map[x][y];
	// int		cx;
	// int		cy;
	// cx = 0;
	// while (cx < x)
	// {
	// 	get_next_line(0, &line);
	// 	ft_strcpy(map[cx] ,(ft_strsplit((const char *)line, ' ')[1]));
	// 	cx++;
	// }
	// cx = 0;
	// while (cx < x)
	// {
	// 	cy = 0;
	// 	while(cy < y)
	// 	{
	// 		if(map[cx][cy] == 'O' || map[cx][cy] == 'o' )
	// 		{
	// 			ft_putstr(ft_itoa(cx));
	// 			ft_putstr(" ");
	// 			ft_putendl(ft_itoa(cy));
	// 		}
	// 		cy++;
	// 	}
	// 	cx++;
	// }


// if (overlap == 1)
// 	{

// 		ft_putnbr(mdim.x);
// 		ft_putstr(" ");
// 		ft_putnbr(mdim.y + 1);
// 		ft_putendl("");
// 	}
// 	if (overlap == 1)
// 	{
// 		ft_putendl("+++++++++++++++++++++++++++++++++++variables+++++++++++++++++++++++++++++++++++");
// 		ft_putstr("mdim.ht :");
// 		ft_putnbr(mdim.ht);
// 		ft_putendl("");
// 		ft_putstr("mdim.wt :");
// 		ft_putnbr(mdim.wt);
// 		ft_putendl("");
// 		ft_putstr("mdim.x :");
// 		ft_putnbr(mdim.x);
// 		ft_putendl("");
// 		ft_putstr("mdim.y :");
// 		ft_putnbr(mdim.y);
// 		ft_putendl("");
// 		ft_putstr("pdim.ht :");
// 		ft_putnbr(pdim.ht);
// 		ft_putendl("");
// 		ft_putstr("pdim.wt :");
// 		ft_putnbr(pdim.wt);
// 		ft_putendl("");
// 		ft_putstr("pdim.x :");
// 		ft_putnbr(pdim.x);
// 		ft_putendl("");
// 		ft_putstr("pdim.y :");
// 		ft_putnbr(pdim.y);
// 		ft_putendl("");
// 		ft_putstr("overlap :");
// 		ft_putnbr(overlap);
// 		ft_putendl("");	
// 	}






























// #include "filler.h"
// #include <fcntl.h>
// #include <stdlib.h>
// int		main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i = 0;
// 	char	*filename;

// 	filename = "logger.txt";
// 	system("rm logger.txt; touch logger.txt");
// 	while(i < 21)
// 	{
// 		get_next_line(0, &line);
// 		fd = open(filename, O_RDWR | O_APPEND);
// 		ft_putendl_fd(line, fd);
// 		close(fd);
// 		i++;
// 	}
// 	ft_putendl("8 2");
// 	while(i < 100)
// 	{
// 		get_next_line(0, &line);
// 		fd = open(filename, O_RDWR | O_APPEND);
// 		ft_putendl_fd(line, fd);
// 		close(fd);
// 		i++;
// 	}
// 	return(0);
// }
