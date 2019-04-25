#include "lem-in.h"

t_rooms *g_queue;
static	ssize_t num = -1;

void remove_parents()
{
	ssize_t i;

	i = -1;
	while (++i < g_queue->len)
		g_queue->arr[i]->parent = NULL;
	g_queue->len = 1;
}

void	add_path()
{
	t_room	*room;

	room = g_head;
	++num;
	push_array(g_path, new_array(1));
	g_path->arr[num]->pathlen = 1;
	while (room->parent)
	{
		push_array(g_path->arr[num], room);
		room->visited = true;
		g_path->arr[num]->pathlen++;
		room = room->parent;
	}
	push_array(g_path->arr[num], g_tail);
	if (g_head->parent != g_tail)
		g_head->visited = 0;
}

void	add_to_queue(t_room *room)
{
	ssize_t		i;

	i = -1;
	while (++i < room->links->len)
	{
		if (room->links->arr[i]->parent ||
		room->links->arr[i] == g_tail || room->links->arr[i]->visited)
			continue;
		room->links->arr[i]->parent = room;
		push_array(g_queue, room->links->arr[i]);
	}
}

void	algorithm()
{
	ssize_t i;

	i = -1;
	g_queue = new_array(1);
	g_path = new_array(1);
	push_array(g_queue, g_tail);
	while (++i < g_queue->len)
	{
		if (g_queue->arr[i] == g_head)
		{
			add_path();
			remove_parents();
			i = -1;
			continue;
		}
		add_to_queue(g_queue->arr[i]);
	}
}
