#include "lem-in.h"

int main()
{
	g_rooms = new_array(40);
	parse();
	algorithm();
//	show_output();
//	print_rooms();
//	system("leaks -q Lem_in");
	return 0;
}