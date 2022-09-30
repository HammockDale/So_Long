#include "ft_printf.h"

static int	shir_zero(int strLen, int d, t_flag flag)
{
	if (flag.shir < 0)
	{
		write(1, "(null)", strLen);
		d += strLen;
		d = ft_printchr(' ', -flag.shir, d);
	}
	else
	{
		d = ft_printchr('0', flag.shir, d);
		write(1, "(null)", strLen);
		d += strLen;
	}
	return (d);
}

static int	shir(int strLen, int d, t_flag flag)
{
	if (flag.shir < 0)
	{
		write(1, "(null)", strLen);
		d += strLen;
		d = ft_printchr(' ', -flag.shir, d);
	}
	else
	{
		d = ft_printchr(' ', flag.shir, d);
		write(1, "(null)", strLen);
		d += strLen;
	}
	return (d);
}

int	ft_s_null(int d, char **p, t_flag flag, int strLen)
{
	(*p)++;
	if (flag.dot_ex)
		if (strLen > flag.dot && flag.dot >= 0)
			strLen = flag.dot;
	if (flag.shir > strLen)
	{
		flag.shir -= strLen;
		if (flag.sdvig)
			flag.shir *= flag.sdvig;
		if (flag.zero)
			d = shir_zero(strLen, d, flag);
		else
			d = shir(strLen, d, flag);
	}
	else
	{
		write(1, "(null)", strLen);
		d += strLen;
	}
	return (d);
}
