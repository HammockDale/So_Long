#include "ft_printf.h"

int	ft_c(int d, int c, char **p, t_flag flag)
{
	if (flag.shir)
		flag.shir -= 1;
	if (flag.sdvig)
		flag.shir *= flag.sdvig;
	if (flag.space)
	{
		write(1, " ", 1);
		d++;
		flag.shir--;
	}
	if (flag.zero)
		d = ft_printchr('0', flag.shir, d);
	else
		d = ft_printchr(' ', flag.shir, d);
	write(1, &c, 1);
	d++;
	d = ft_printchr(' ', -flag.shir, d);
	(*p)++;
	return (d);
}
