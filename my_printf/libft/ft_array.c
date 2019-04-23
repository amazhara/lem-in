#include "libft.h"

void	*new_array(size_t amount)
{
	t_array	*res;

	res = malloc(sizeof(t_array));
	res->arr = malloc(sizeof(t_array) * amount);
	res->len = 0;
	res->max = amount;
	return (res);
}

void	*push_array(void *dst ,void *elem)
{
	t_array	*cast;
	t_array	**tmp;

	cast = (t_array*)dst;
	if (cast->len >= cast->max)
	{
		cast->max *= 2;
		tmp = malloc(cast->max * sizeof(t_array*));
		ft_memcpy(tmp, cast->arr, sizeof(t_array*) * cast->len);
		free(cast->arr);
		cast->arr = (void **)tmp;
	}
	return ((cast->arr[cast->len++] = elem));
}

//t_rooms	*new_array(size_t amount)
//{
//	t_rooms		*res;
//
//	res = malloc(sizeof(t_rooms));
//	res->arr = malloc(sizeof(t_room) * amount);
//	res->len = 0;
//	res->max = amount;
//	return (res);
//}

//t_room	*push_array(t_rooms *rooms, t_room *elem)
//{
//	t_room	**tmp;
//
//	if (rooms->len >= rooms->max)
//	{
//		rooms->max *= 2;
//		tmp = malloc(rooms->max * sizeof(t_room*));
//		ft_memcpy(tmp, rooms->arr, sizeof(t_room*) * rooms->len);
//		free(rooms->arr);
//		rooms->arr = tmp;
//	}
//	return ((rooms->arr[rooms->len++] = elem));
//}
