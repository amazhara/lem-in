/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:42:42 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:21:00 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_error(char *er_message)
{
	ft_memcpy(g_error, er_message, ft_strlen(er_message));
}

void	check_line(char *line)
{
	if (!(*line))
		return (add_error("Empty lines"));
	if ((*line) == ' ' || (*line) == '\t')
		return (add_error("Wrong extra symbols"));
	if (*line == 'L')
		return (add_error("Wrong room name"));
	if ((ft_intlen(ft_atoi(line)) == (intmax_t)ft_strlen(line)) && g_antscount)
		return (add_error("Wrong symbol"));
	take_line(line);
}

void	validate_coordinate(int coords[2])
{
	ssize_t i;

	i = -1;
	while (++i < g_valid_coords->len - 1)
	{
		if (((int*)g_valid_coords->arr[i])[0] == coords[0] &&
		((int*)g_valid_coords->arr[i])[1] == coords[1])
			return (add_error("Same room coords"));
	}
}

void	validate(void)
{
	if (g_antscount < 0 || g_antscount > 0x7FFFFFFF || !g_antscount)
		return (add_error("Wrong ants count"));
	if (!g_head || !g_tail)
		return (add_error("Wrong properties"));
	if (!g_head->links->arr[0] || !g_tail->links->arr[0])
		return (add_error("Links not related"));
}
