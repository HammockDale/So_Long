#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	n;

	n = ft_strlen(s);
	if (c == 0)
		return ((char *) s + n);
	while (n > 0 && ft_isascii(c))
	{
		if (s[n] == (unsigned char) c)
			return ((char *)(s + n));
		n--;
	}
	if (s[n] == (unsigned char) c)
		return ((char *)(s + n));
	return (NULL);
}
