#include "ft_printf.h"

int	ft_printchr(char c, int len, int d)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		d++;
	}
	return (d);
}
