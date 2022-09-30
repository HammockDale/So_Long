#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	ch;

	if (ft_isascii(c) > 0)
	{
		ch = (char)c;
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			return (1);
		}
	}
	return (0);
}
