#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	size_t	l;

	if (!s)
		return (NULL);
	str = (char *)s;
	l = ft_strlen(s) - start;
	if (l <= len)
		str = (char *)malloc((sizeof(char)) * (l + 1));
	else
		str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	n = start;
	l = 0;
	while (n < ft_strlen(s) && l < len)
	{
		str[l++] = s[n++];
	}
	str[l] = 0;
	return (str);
}
