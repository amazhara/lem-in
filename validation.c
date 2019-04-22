#include "lem-in.h"

void	valid_antcount(int antcount)
{
	if (antcount <= 0)
		add_error("Invalid ants number");
}
