#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	if (*needle == 0)
		return ((char *) hay);
	while (i < len && *hay != 0)
	{
		while (hay[i] == needle[n] && i < len)
		{
			i++;
			n++;
			if (needle[n] == 0)
				return ((char *)(hay + i - n));
		}
		i = i + 1 - n;
		n = 0;
	}
	return (NULL);
}
