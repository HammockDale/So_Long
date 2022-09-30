#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	s;
	size_t	d;

	d = 0;
	s = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (s + 1));
	if (!str)
		return (NULL);
	while (d < s && src[d])
	{
		str[d] = src[d];
		d++;
	}
	str[d] = 0;
	return (str);
}
