#include "lem-in.h"

int main(int ac, char **av)
{
	if (!take_args(av))
		return (0);
	g_rooms = new_array(40);
	parse();
	algorithm();
	if (!g_av.silent)
		show_output();
	release_ants();
	print_args();
	return 0;
}
