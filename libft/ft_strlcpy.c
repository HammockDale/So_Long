#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			k;
	unsigned char	*str;
	unsigned char	*copy;

	str = (unsigned char *) dst;
	copy = (unsigned char *) src;
	k = 0;
	if (dst != 0 || src != 0)
	{
		if (dstsize != 0)
		{
			while (k < (dstsize - 1) && src[k] != 0)
			{
				str[k] = copy[k];
				k++;
			}
			dst[k] = 0;
		}
		return (ft_strlen(src));
	}	
	return (0);
}
