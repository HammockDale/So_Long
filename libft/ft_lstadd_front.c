#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old;

	old = lst[0];
	lst[0] = new;
	new->next = old;
}
