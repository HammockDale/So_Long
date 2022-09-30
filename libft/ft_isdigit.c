#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ft_isascii(c) != 0)
	{
		if (ch >= '0' && ch <= '9')
		{
			return (1);
		}
	}
	return (0);
}
