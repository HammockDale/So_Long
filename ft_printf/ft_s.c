#include "ft_printf.h"

static int	shir_zero(int d, t_flag flag, int strLen, char *str)
{
	if (flag.shir < 0)
	{
		write(1, str, strLen);
		d += strLen;
		d = ft_printchr(' ', -flag.shir, d);
	}
	else
	{
		d = ft_printchr('0', flag.shir, d);
		write(1, str, strLen);
		d += strLen;
	}
	return (d);
}

static int	shir(int d, t_flag flag, int strLen, char *str)
{
	if (flag.zero)
		return (shir_zero(d, flag, strLen, str));
	if (flag.shir < 0)
	{
		write(1, str, strLen);
		d += strLen;
		d = ft_printchr(' ', -flag.shir, d);
	}
	else
	{
		d = ft_printchr(' ', flag.shir, d);
		write(1, str, strLen);
		d += strLen;
	}
	return (d);
}

int	ft_s(int d, char *str, char **p, t_flag flag)
{
	int		strLen;

	if (!str)
		return (ft_s_null(d, p, flag, 6));
	(*p)++;
	strLen = ft_strlen(str);
	if (flag.dot_ex && flag.dot < 0)
		flag.dot = strLen;
	else if (flag.dot_ex && strLen > flag.dot)
		strLen = flag.dot;
	if (flag.shir > strLen)
	{
		flag.shir -= strLen;
		if (flag.sdvig)
			flag.shir *= flag.sdvig;
		d = shir(d, flag, strLen, str);
	}
	else
	{
		write(1, str, strLen);
		d += strLen;
	}
	return (d);
}
