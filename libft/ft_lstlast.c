#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*s;

	if (!lst)
		return (NULL);
	s = lst;
	while (s->next)
	{
		s = s->next;
	}
	return (s);
}
