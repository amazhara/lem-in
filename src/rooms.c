/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:42:33 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 15:54:29 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*add_room(char **names)
{
	t_room	*room;

	if (!ft_isnum(names[1]) || !ft_isnum(names[2]) || !names[0])
	{
		add_error("Wrong coordinate or empty room name");
		return (NULL);
	}
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
	ssize_t	i;

	i = -1;
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

	if (!(first_room = search_room(names[0])))
		return (add_error("No such room to connect"));
	if (!(second_room = search_room(names[1])))
		return (add_error("No such room to connect"));
	push_array(first_room->links, second_room);
	push_array(second_room->links, first_room);
	ft_double_free(names, 1);
}
