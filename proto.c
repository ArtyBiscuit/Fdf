typedef	s_point	t_point;

struct	s_point{
	int		x;
	int		y;
	int		z;
	int		color;
	t_point	*next;
};

char	*get_data(char *path_file)
{
	int	fd;

	fd = open(path_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = get_next_line(fd);
	
	
}
