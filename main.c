#include "filler.h"
#include <fcntl.h>
int		main(void)
{
	//char	*line;
	int		fd;
	char	*filename;

	//get_next_line(1, &line);
	filename = "logger.txt";
	fd = open(filename, O_RDONLY);
	ft_putendl_fd("test", fd);
	ft_putendl("test");
	close(fd);
	return(0);
}
