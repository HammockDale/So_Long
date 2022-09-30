#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = *lst;
	if (!lst || !del)
		return ;
	while (new_lst)
	{
		tmp = new_lst->next;
		if (del)
			del(new_lst->content);
		free(new_lst);
		new_lst = tmp;
	}
	*lst = NULL;
}
