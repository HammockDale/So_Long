#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd >= 0 && s)
	{
		i = 0;
		while (i < ft_strlen(s))
		{
			ft_putchar_fd(s[i++], fd);
		}
	}
}
