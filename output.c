#include "lem-in.h"

void	print_room(t_room *room)
{
	ft_printf("\033[01;03;38;05;226m{%s} \033[03;38;05;253m[%d, %d]", room->name, room->coords[0], room->coords[1]);
};

void	print_rooms(t_rooms *rooms)
{
	ssize_t i;
	ssize_t j;

	i = -1;
	if (!rooms)
		rooms = g_rooms;
	while (++i < rooms->len)
	{
		j = -1;
		print_room(rooms->arr[i]);
		if (rooms->arr[i]->links->arr[0]->name)
			while (++j < rooms->arr[i]->links->len)
				ft_printf(" \033[01;03;38;05;51m%s ", rooms->arr[i]->links->arr[j]->name);
		ft_printf("\n");
	}
	ft_printf("\033[01;03;38;05;253m");
}

void	print_stat()
{
	ft_printf("\033[38;05;68mStatistic:\nefficiency %d vs %d\n", g_stat[0], g_stat[1]);
	ft_printf("\033[01;03;38;05;253m");
}

void	show_output()
{
	ssize_t i;

	i = -1;
	while (++i < g_out->len)
		ft_printf("%s\n", (char*)g_out->arr[i]);
}

void	print_paths()
{
	ssize_t		i;
	ssize_t 	j;

	i = -1;
	while (++i < g_path->len) {
		ft_printf("\nPATH: \033[01;03;38;05;46m%d\n\033[03;38;05;166m\n-------\n", i);
		j = -1;
		while (++j < g_path->arr[i]->len)
			ft_printf("\033[03;38;05;180m {%.5s}\n", g_path->arr[i]->arr[j]->name);
		ft_printf("\033[01;03;38;05;226m\nlen - %d\n", g_path->arr[i]->pathlen);
		ft_printf("\033[03;38;05;166m\n-------\n\033[01;03;38;05;253m");
	}
}
