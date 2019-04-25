#include "lem-in.h"

void	print_usage()
{
	ft_printf("\noptions:\n"
			  "\t--path : Show found paths\n"
			  "\t--help : to read the manual\n"
			  "\t--silent : silent ants and file output\n"
			  "\t--stat : print the program execute statistic\n"
			  "\t--rooms : show rooms, their links and coordinates\n");
}

int		take_args(char **usr_av)
{
	ft_bzero(&g_av, sizeof(t_args));
	while (*usr_av)
	{
		if (!ft_strcmp(*usr_av, "--help"))
		{
			print_usage();
			return (0);
		}
		if (!ft_strcmp(*usr_av, "--silent"))
			g_av.silent = true;
		if (!ft_strcmp(*usr_av, "--rooms"))
			g_av.rooms = true;
		if (!ft_strcmp(*usr_av, "--leaks"))
			g_av.leaks = true;
		if (!ft_strcmp(*usr_av, "--path"))
			g_av.path = true;
		if (!ft_strcmp(*usr_av++, "--stat"))
			g_av.stat = true;
	}
	return (1);
}

void	print_args()
{
	if (g_av.rooms)
		print_rooms(NULL);
	if (g_av.path)
		print_paths();
	if (g_av.stat)
		print_stat();
	if (g_av.leaks)
		system("leaks -q Lem_in");
}
