/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:42:01 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:31:29 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*g_ants;

void	take_ant(t_room *room)
{
	ssize_t		i;
	char		*num;

	i = -1;
	while (++i < g_ants->len)
		if (g_ants->arr[i] && g_ants->arr[i] == room)
		{
			g_ants->arr[i] = NULL;
			num = ft_itoa(i + 1);
			room->ant = ft_strjoin("L", num);
			if (!g_av.silent)
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
			if (!g_av.silent)
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
	ssize_t		i;
	ssize_t		len;

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

void	right_way(void)
{
	int			i;

	i = 0;
	while (g_antscount--)
	{
		if (!g_av.silent)
			ft_printf("%s%d-%s ", "L", ++i, g_tail->name);
	}
	if (!g_av.silent)
		ft_printf("\n");
}

void	release_ants(void)
{
	ssize_t count;
	ssize_t i;
	int		lines;

	lines = 0;
	count = g_antscount;
	g_ants = new_array((size_t)g_antscount);
	if (g_path->arr[0]->arr[0] == g_head && g_path->arr[0]->arr[1] == g_tail)
		return (right_way());
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
		if (!g_av.silent)
			ft_printf("\n");
		lines++;
	}
	g_stat[0] = lines;
}
