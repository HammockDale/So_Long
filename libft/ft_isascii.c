#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 128 && c > 0)
		return (c);
	if (c == 0)
		return (128);
	return (0);
}
