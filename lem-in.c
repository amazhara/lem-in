#include "lem-in.h"

int main()
{
	g_rooms = new_array(1);
	parse();
	print_rooms();
	return 0;
}