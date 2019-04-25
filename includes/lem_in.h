/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:41:43 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:11:57 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../my_printf/libftprintf.h"

typedef struct s_rooms	t_rooms;
typedef struct s_room	t_room;
typedef struct s_path	t_path;
typedef struct s_args	t_args;

struct	s_args
{
	short	stat;
	short	path;
	short	rooms;
	short	leaks;
	short	silent;
};

struct	s_rooms
{
	t_room	**arr;
	ssize_t len;
	ssize_t max;
	ssize_t	pathlen;
};

struct	s_room
{
	int		visited;
	char	*ant;
	int		coords[2];
	char	*name;
	t_room	*parent;
	t_rooms	*links;
};

struct	s_path
{
	t_rooms	**arr;
	ssize_t len;
	ssize_t max;
};

void	validate_coordinate(int	coords[2]);
void	print_rooms(t_rooms *rooms);
void	add_error(char *er_message);
void	print_room(t_room *room);
t_room	*search_room(char *name);
t_room	*add_room(char **names);
void	check_line(char *line);
void	add_link(char **names);
void	take_line(char *line);
int		take_args(char **av);
void	release_ants();
void	show_output();
void	print_paths();
void	print_usage();
void	print_args();
void	print_stat();
void	algorithm();
void	validate();
void	parse();

t_rooms	*g_valid_coords;
t_rooms	*g_rooms;
t_rooms	*g_out;
t_path	*g_path;
t_room	*g_head;
t_room	*g_tail;
t_args	g_av;
int		g_stat[2];
ssize_t	g_antscount;
char	g_error[100];

#endif
