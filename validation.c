#include "lem-in.h"

void	valid_antcount(int antscount)
{
	if (antscount <= 0)
		add_error("Invalid ants number");
}