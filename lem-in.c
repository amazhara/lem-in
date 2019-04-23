#include "lem-in.h"

int main()
{
	g_rooms = new_array(40);
	parse();
	algorithm();
	release_ants();
//	print_paths();
//	show_output();
//	print_rooms();
//	system("leaks -q Lem_in");
	return 0;
}