#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_lst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_lst = ft_lstlast(*lst);
	new_lst->next = new;
	new_lst->next->next = NULL;
}
