#include "lem-in.h"
#include "my_printf/includes/ft_printf.h"

static int 	head_point = false;
static int 	tail_point = false;

void	explode_properties(char *line)
{
	t_room	*room;

	room = add_room(ft_strsplit(line, ' '));
	if (head_point && !g_head)
		g_head = room;
	else if (tail_point && !g_tail)
		g_tail = room;
	else
		add_error("More then one property");
	head_point = false;
	tail_point = false;
}

void	take_properties(char *line)
{
	if (line[1] == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			head_point = true;
		else if (!ft_strcmp(line + 2, "end"))
			tail_point = true;
		else
			add_error("Wrong property");
	}
}

void	check_line(char *line)
{
	if (!(*line))
		return add_error("Empty lines");
	if (*line == 'L')
		return add_error("Wrong room name");
	if (ft_intlen(ft_atoi(line)) == ft_strlen(line))
		return (valid_antcount((g_antscount = ft_atoi(line))));
	if (*line == '#')
		return (take_properties(line));
	if (ft_strchr(line, ' '))
		add_room(ft_strsplit(line, ' '));
	if (ft_strchr(line, '-'))
		add_link(ft_strsplit(line, '-'));
}

void	parse()
{
	int 	fd;
	char 	*line = NULL;

	g_out = new_array(1000);
	fd = open("../big", O_RDONLY);
	while (!(*g_error) && get_next_line(fd, &line) > 0)
	{
		if (head_point || tail_point)
			explode_properties(line);
		else
			check_line(line);
		push_array(g_out, (t_room*)line);
	}
	if (*g_error)
	{
		ft_printf("%s\n", g_error);
		exit(0);
	}
}
