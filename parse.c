#include "lem-in.h"

static int 	head_point = false;
static int 	tail_point = false;
static int 	i = false;


void	take_properties(char *line)
{
	if (line[1] == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			head_point = true;
		if (!ft_strcmp(line + 2, "end"))
			tail_point = true;
	}
}

void	check_line(char *line)
{
//	if (ft_strchr(line, '-'))
//		return;
	if (!(*line))
		return add_error("Empty lines");
	if (ft_intlen(ft_atoi(line)) == ft_strlen(line))
		return (valid_antcount((g_antscount = ft_atoi(line))));
	if (*line == '#')
		return (take_properties(line));
	if (ft_strchr(line, ' '))
		add_room(ft_strsplit(line, ' '));
//	else
//		add_link(ft_strsplit(line, '-'));
}

void	parse()
{
	int 	fd;
	char 	*line = NULL;

	out = new_array(1000);
	fd = open("../file1", O_RDONLY);
	while (get_next_line(fd, &line) > 0 && !(*g_error))
	{
		check_line(line);
//		printf("%s\n", line);
		free(line);
	}

}
