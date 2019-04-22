#include "lem-in.h"

t_rooms	*new_array(size_t amount)
{
	t_rooms		*res;

	res = malloc(sizeof(t_rooms));
	res->arr = malloc(sizeof(t_room) * amount);
	res->len = 0;
	res->max = amount;
	return (res);
}

t_room	*push_array(t_room *elem)
{
	t_room	**tmp;

	if (g_rooms->len >= g_rooms->max)
	{
		g_rooms->max *= 2;
		tmp = malloc(g_rooms->max * sizeof(t_room*));
		ft_memcpy(tmp, g_rooms->arr, sizeof(t_room*) * g_rooms->len);
		free(g_rooms->arr);
		g_rooms->arr = tmp;
	}
	return ((g_rooms->arr[g_rooms->len++] = elem));
}


void	add_room(char **names)
{
	t_room	*room;

//	printf("%s %s %s\n", names[0], names[1], names[2]);
	room = malloc(sizeof(t_room));
	room->name = ft_strdup(names[0]);
	room->coords[0] = ft_atoi(names[1]);
	room->coords[1] = ft_atoi(names[2]);
	printf("%s %d %d\n", room->name, room->coords[0], room->coords[1]);
//	room->links = new_array(4);
	push_array(room);
//	ft_double_free(names, 2);
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
//	push_array(first_room->links, second_room);
//	push_array(second_room->links, first_room);
}
