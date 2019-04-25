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

void	take_line(char *line)
{
	if (ft_intlen(ft_atoi(line)) == ft_strlen(line))
	{
		g_antscount = ft_atoi(line);
		return ;
	}
	if (*line == '#')
		return (take_properties(line));
	if (strchr_count(line, ' ') == 2)
	{
		push_array(valid_coords, add_room(ft_strsplit(line, ' '))->coords);
		validate_coordinate((int*)valid_coords->arr[valid_coords->len - 1]);
	}
	if (strchr_count(line, ' ') != 2 && strchr_count(line, '-') == 1)
		add_link(ft_strsplit(line, '-'));
}

void	parse()
{
	int 	fd;
	char 	*line = NULL;

	g_out = new_array(1000);
	valid_coords = new_array(100);
	fd = open("../super", O_RDONLY);
	while (!(*g_error) && get_next_line(0, &line) > 0)
	{
		if (head_point || tail_point)
			explode_properties(line);
		else
			check_line(line);
		push_array(g_out, (t_room*)line);
	}
	if (!*g_error)
		validate();
	if (*g_error)
	{
		ft_printf("%s\n", g_error);
		exit(0);
	}
}
