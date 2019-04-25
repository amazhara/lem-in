#include "lem-in.h"

void	print_room(t_room *room)
{
	ft_printf("name ---> %s  {%d, %d}", room->name, room->coords[0], room->coords[1]);
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
				ft_printf(" %s ", rooms->arr[i]->links->arr[j]->name);
		ft_printf("\n");
	}
}

void	show_output()
{
	ssize_t i;

	i = -1;
	while (++i < g_out->len)
	{
		ft_printf("%s\n", (char*)g_out->arr[i]);
	}
}

void	print_paths()
{
	ssize_t		i;
	ssize_t 	j;
	ssize_t 	num;

	i = -1;
	while (++i < g_path->len)
	{
		ft_printf("{Path} %d {\n*******\n", i);
		j = -1;
		num = -1;
		while (++j < g_path->arr[i]->len)
			ft_printf("%d | name ---> %s\n", ++num, g_path->arr[i]->arr[j]->name);
		ft_printf("----\n*%d*\n----\n", g_path->arr[i]->pathlen);
		ft_printf("*******\n}\n\n");
	}
}
