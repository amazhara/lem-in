#ifndef LEM_IN_H
# define LEM_IN_H
# include "my_printf/libft/libft.h"
# include <stdio.h>

typedef struct	s_rooms	t_rooms;
typedef struct	s_room	t_room;

struct	s_rooms
{
	t_room	**arr;
	ssize_t len;
	ssize_t max;
};

struct	s_room
{
	char	*name;
	int 	coords[2];
	t_rooms	*links;
};

void	print_room(t_room *room);
void	print_rooms();
void	add_error(char *er_message);
void	valid_antcount(int antscount);
void	algorithm();
t_room	*search_room(char *name);
void	show_output();
void	add_link(char **names);
t_room * add_room(char **names);
void	print(char *line);
t_rooms	*new_array(size_t amount);
t_room	*push_array(t_rooms *rooms, t_room *elem);
void	parse();

static void	(*echo)(char*) = &print;

t_rooms	*g_rooms;
t_rooms	*out;
t_room	*g_head;
t_room	*g_tail;
int 	g_antscount;
char 	g_error[100];

# endif
