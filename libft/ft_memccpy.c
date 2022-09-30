#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*copy;

	str = (unsigned char *) dest;
	copy = (unsigned char *) src;
	while (n > 0)
	{
		*str = *copy;
		if (*copy == (unsigned char) c)
		{
			return (++dest);
		}
		str++;
		copy++;
		dest++;
		n--;
	}
	return (NULL);
}
