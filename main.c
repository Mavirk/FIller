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
		get_next_line(0, &line);
		piece[++cx] = ft_strsplit((const char *)line, ' ')[0];
		ft_strdel(&line);
	}
	return(piece);
}

void 	get_move(char **map, char **piece)
{
	int     flag;
	int 	mx;
	int 	my;
	int 	px;
	int 	py;

	flag = 0;
	mx = 0;
	my = 0;
	while (map[mx] && flag = 0)
	{
		mx++;
		my = 0;
		while ((map[mx][my] != 'O' || map[mx][my] != 'o') && map[mx][my])
			my++;
		if ((map[mx][my] == 'O' || map[mx][my] == 'o'))
			flag = 1;
	}
	px = 0;
	while (piece[px])
	{
		py = 0;
		while (piece[px][py])
		{
			py++;
		}
		px++;
	}
	ft_putnbr(mx);
	ft_putstr(" ");
	ft_putnbr(my);
}

int		main(void)
{
	// int 	i;
	int 	p;
	int 	x;
	int		y;
	int 	px;
	int 	py;
	char	**map;
	char 	**piece;

	get_player(&p);
	get_input(&x, &y);
	map = get_map(x);
	get_input(&px, &py);
	piece = get_piece(px);
	get_move(map, piece);
	return (0);
}



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
