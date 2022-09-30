#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	n;

	str = NULL;
	if (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		n = ft_strlen(s1);
		while (n && ft_strchr(set, s1[n]))
			n--;
		str = ft_substr(s1, 0, n + 1);
	}
	return (str);
}
