/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:42:17 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:13:08 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	if (!take_args(av))
		return (0);
	(void)ac;
	g_rooms = new_array(40);
	parse();
	algorithm();
	if (!g_av.silent)
		show_output();
	release_ants();
	print_args();
}
