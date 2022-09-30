#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (n > 0)
	{
		*temp = (unsigned char) c;
		n--;
		temp++;
	}
	return (str);
}
