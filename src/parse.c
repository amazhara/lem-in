/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:43:04 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:19:50 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	g_head_point = false;
static int	g_tail_point = false;

void	explode_properties(char *line)
{
	t_room	*room;

	room = add_room(ft_strsplit(line, ' '));
	if (g_head_point && !g_head)
		g_head = room;
	else if (g_tail_point && !g_tail)
		g_tail = room;
	else
		add_error("More then one property");
	g_head_point = false;
	g_tail_point = false;
}

void	take_properties(char *line)
{
	if (line[1] == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			g_head_point = true;
		else if (!ft_strcmp(line + 2, "end"))
			g_tail_point = true;
		else
			add_error("Wrong property");
	}
}

void	take_line(char *line)
{
	if (ft_intlen(ft_atoi(line)) == (intmax_t)ft_strlen(line))
	{
		g_antscount = ft_atoi(line);
		return ;
	}
	if (ft_strstr(line, "#Here is the number of lines required: "))
		g_stat[1] = ft_atoi(line + 38);
	if (strchr_count(line, ' ') == 2)
	{
		if (g_head_point || g_tail_point)
			explode_properties(line);
		push_array(g_valid_coords, add_room(ft_strsplit(line, ' '))->coords);
		validate_coordinate((int*)g_valid_coords->arr[g_valid_coords->len - 1]);
	}
	if (*line == '#')
		return (take_properties(line));
	if (strchr_count(line, ' ') != 2 && strchr_count(line, '-') == 1)
		add_link(ft_strsplit(line, '-'));
}

void	parse(void)
{
	char	*line;

	line = NULL;
	g_out = new_array(1000);
	g_valid_coords = new_array(100);
	while (!(*g_error) && get_next_line(0, &line) > 0)
	{
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
