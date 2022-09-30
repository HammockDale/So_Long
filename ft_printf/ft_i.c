#include "ft_printf.h"

static int	shir(t_flag flag, int d, int strLen, char *in_ten)
{
	if (flag.znac < 0)
		write(1, "-", 1);
	else if (flag.plus)
		write(1, "+", 1);
	if (flag.zero)
	{
		while (flag.shir > 0 && flag.shir > flag.dot)
		{
			write(1, "0", 1);
			flag.shir--;
			d++;
		}
	}
	while (flag.dot > strLen)
	{
		write(1, "0", 1);
		flag.dot--;
		flag.shir++;
		d++;
	}
	write(1, in_ten, strLen);
	d += strLen;
	return (d);
}

static int	unshir(t_flag flag, int d, int strLen, char *in_ten)
{
	if (flag.znac < 0)
		write(1, "-", 1);
	else if (flag.plus)
		write(1, "+", 1);
	while (flag.dot > strLen)
	{
		write(1, "0", 1);
		flag.dot--;
		flag.shir++;
		d++;
	}
	write(1, in_ten, strLen);
	d += strLen;
	flag.shir = flag.shir + strLen;
	while (flag.shir < 0)
	{
		write(1, " ", 1);
		flag.shir++;
		d++;
	}
	return (d);
}

static int	ft_prodolg(t_flag flag, int d, int strLen, char *in_ten)
{
	if (flag.dot < strLen)
		flag.dot = strLen;
	if (flag.sdvig)
		flag.shir *= flag.sdvig;
	if (!flag.zero || flag.dot_ex)
	{
		while (flag.shir > flag.dot)
		{
			write(1, " ", 1);
			flag.shir--;
			d++;
		}
	}
	if (flag.shir < 0)
	{
		d = unshir(flag, d, strLen, in_ten);
	}
	else
	{
		d = shir(flag, d, strLen, in_ten);
	}
	free(in_ten);
	return (d);
}

static int	ft_znac(t_flag *flag, int d)
{
	if (flag->dot < 0)
		flag->dot_ex = 0;
	if (flag->plus)
	{
		flag->shir--;
		d++;
	}
	else if (flag->space)
	{
		write(1, " ", 1);
		d++;
		flag->shir--;
	}
	return (d);
}

int	ft_i(int d, int i, char **p, t_flag flag)
{
	char	*in_ten;
	int		strLen;

	(*p)++;
	if (i < 0)
	{
		flag.znac = -1;
		i = -(i);
		flag.plus = 1;
	}
	d = ft_znac(&flag, d);
	in_ten = ft_itoa(i);
	strLen = ft_strlen(in_ten);
	if (flag.dot_ex && flag.dot == 0 && i == 0)
		strLen = flag.dot;
	d = ft_prodolg(flag, d, strLen, in_ten);
	return (d);
}
