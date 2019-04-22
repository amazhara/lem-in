#include "lem-in.h"

int main()
{
	g_rooms = new_array(40);
//	ft_printf("aho");
	parse();
	print_rooms();
	return 0;
}