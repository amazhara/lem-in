#ifndef LEM_IN_H
# define LEM_IN_H
# include "my_printf/libft/libft.h"
#include "my_printf/includes/ft_printf.h"
# include <stdio.h>

typedef struct	s_rooms	t_rooms;
typedef struct	s_room	t_room;
typedef struct	s_path	t_path;

struct	s_rooms
{
	t_room	**arr;
	ssize_t len;
	ssize_t max;
	ssize_t	pathlen;
};

struct	s_room
{
	int 	visited;
	int 	coords[2];
	char	*name;
	t_room 	*parent;
	t_rooms	*links;
};

struct	s_path
{
	t_rooms	**arr;
	ssize_t len;
	ssize_t max;
};

void	print_room(t_room *room);
void	print_rooms();
void	add_error(char *er_message);
void	valid_antcount(int antscount);
void	print_paths();
void	algorithm();
t_room	*search_room(char *name);
void	show_output();
void	add_link(char **names);
t_room	*add_room(char **names);
void	parse();

t_rooms	*g_rooms;
t_path	*g_path;
t_rooms	*out;
t_room	*g_head;
t_room	*g_tail;
int 	g_antscount;
char 	g_error[100];

# endif
