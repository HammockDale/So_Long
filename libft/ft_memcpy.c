#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*copy;

	str = (unsigned char *) dest;
	copy = (unsigned char *) src;
	if (dest == src)
		return (dest);
	while (n > 0)
	{
		*str = *copy;
		str++;
		copy++;
		n--;
	}
	return (dest);
}
