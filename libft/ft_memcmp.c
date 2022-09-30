#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			k;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	k = 0;
	while (k < n)
	{
		if (st1[k] != st2[k])
			return (st1[k] - st2[k]);
		k++;
	}
	return (0);
}
