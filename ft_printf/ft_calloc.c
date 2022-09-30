#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	n;

	n = count * size;
	str = (void *)malloc(n);
	if (!str)
		return (NULL);
	ft_bzero(str, n);
	return (str);
}
