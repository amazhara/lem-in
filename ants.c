#include "lem-in.h"

t_rooms		*g_ants;

void	take_ant(t_room	*room)
{
	ssize_t 	i;
	char 		*num;

	i = -1;
	while (++i < g_ants->len)
		if (g_ants->arr[i] && g_ants->arr[i] == room)
		{
			g_ants->arr[i] = NULL;
			num = ft_itoa(i + 1);
			room->ant = ft_strjoin("L", num);
			ft_printf("%s-%s ", room->ant, room->name);
			free(num);
			return ;
		}
}

void	moove_next_ant(t_rooms *path)
{
	ssize_t	i;

	i = path->len - 1;
	while (--i)
		if (path->arr[i]->ant)
		{
			ft_printf("%s-%s ", path->arr[i]->ant, path->arr[i + 1]->name);
			if (path->arr[i + 1] == g_tail)
			{
				g_antscount--;
				free(path->arr[i]->ant);
			}
			else
				path->arr[i + 1]->ant = path->arr[i]->ant;
			path->arr[i]->ant = NULL;
		}
}

void	init_ants(ssize_t *count)
{
	ssize_t 	i;
	ssize_t 	len;

	i = -1;
	len = 0;
	while (++i < g_path->len)
	{
		if ((g_path->arr[i]->len * i - len) < *count)
		{
			push_array(g_ants, g_path->arr[i]->arr[1]);
			(*count)--;
		}
		len += g_path->arr[i]->len;
	}
}

void	release_ants()
{
	ssize_t count;
	ssize_t sho = 0;
	ssize_t i;

	count = g_antscount;
	g_ants = new_array((size_t)g_antscount);
	while (count)
		init_ants(&count);
	while (g_antscount)
	{
		i = -1;
		while (++i < g_path->len)
			moove_next_ant(g_path->arr[i]);
		i = -1;
		while (++i < g_path->len)
			take_ant(g_path->arr[i]->arr[1]);
		ft_printf("\n");
		sho++;
	}
	ft_printf("num --> %d\n", sho);
}
