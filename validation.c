#include "lem-in.h"

void	valid_antcount(ssize_t antscount)
{
	if (antscount <= 0)
		add_error("Invalid ants number");
}

void	add_error(char *er_message)
{
	ft_memcpy(g_error, er_message, ft_strlen(er_message));
}
