#include "filler.h"
#include <fcntl.h>
#include <stdlib.h>
int		main(void)
{
	char	*line;
	int		fd;
	int		i = 0;
	char	*filename;

	filename = "logger.txt";
	system("rm logger.txt; touch logger.txt");
	while(i < 21)
	{
		get_next_line(0, &line);
		fd = open(filename, O_RDWR | O_APPEND);
		ft_putendl_fd(line, fd);
		close(fd);
		i++;
	}
	ft_putendl("8 2");
	while(i < 100)
	{
		get_next_line(0, &line);
		fd = open(filename, O_RDWR | O_APPEND);
		ft_putendl_fd(line, fd);
		close(fd);
		i++;
	}
	return(0);
}
