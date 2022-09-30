#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*str;
	unsigned char	*copy;

	str = (unsigned char *)str1;
	copy = (unsigned char *)str2;
	while (n > 0)
	{
		if (*str != *copy)
			return (*str - *copy);
		str++;
		copy++;
		if (*str == 0 && *copy == 0)
			return (0);
		n--;
	}
	return (0);
}
