#include "libft.h"

int		strchr_counr(char *line, char symbol)
{
	int 	i;
	int 	count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == symbol)
			count++;
	}
	return (count);
}