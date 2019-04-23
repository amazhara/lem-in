#include "lem-in.h"

t_room	*add_room(char **names)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(names[0]);
	room->coords[0] = ft_atoi(names[1]);
	room->coords[1] = ft_atoi(names[2]);
	room->links = new_array(4);
	ft_double_free(names, 2);
	return (push_array(g_rooms, room));
}

t_room	*search_room(char *name)
{
	ssize_t i;

	i  = -1;
	while (g_rooms->arr[++i])
	{
		if (!ft_strcmp(g_rooms->arr[i]->name, name))
			return (g_rooms->arr[i]);
	}
	return (NULL);
}


void	add_link(char **names)
{
	t_room	*first_room;
	t_room	*second_room;

	first_room = search_room(names[0]);
	second_room = search_room(names[1]);
	push_array(first_room->links, second_room);
	push_array(second_room->links, first_room);
	ft_double_free(names, 1);
}
