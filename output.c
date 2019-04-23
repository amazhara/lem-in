#include "lem-in.h"
#include "my_printf/includes/ft_printf.h"

void	print_room(t_room *room)
{
	ft_printf("name ---> %s  {%d, %d}", room->name, room->coords[0], room->coords[1]);
};

void	print_rooms()
{
	ssize_t i;
	ssize_t j;

	i = -1;
	while (++i < g_rooms->len)
	{
		j = -1;
		print_room(g_rooms->arr[i]);
		if (g_rooms->arr[i]->links->arr[0]->name)
			while (++j < g_rooms->arr[i]->links->len)
				ft_printf(" %s ", g_rooms->arr[i]->links->arr[j]->name);
		echo("\n");
	}
}

void	show_output()
{
	ssize_t i;

	i = -1;
	while (++i < out->len)
	{
		printf("%s\n", (char*)out->arr[i]);
	}
}

void	print(char *line)
{
	ft_printf("%s", line);
}

void	add_error(char *er_message)
{
	ft_memcpy(g_error, er_message, ft_strlen(er_message));
}
