#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}
