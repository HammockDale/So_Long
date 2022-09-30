#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*copy;
	unsigned long	i;

	i = 1;
	str = (unsigned char *) dst;
	copy = (unsigned char *) src;
	if (dst <= src)
		dst = ft_memcpy(str, copy, len);
	else
	{
		while (i <= len)
		{
			str[len - i] = copy[len - i];
			i++;
		}
	}
	return (dst);
}
