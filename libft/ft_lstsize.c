#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	if (!lst)
		return (0);
	n = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		n++;
	}
	n++;
	return (n);
}
