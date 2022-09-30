#include "ft_printf.h"

static int	shir(t_flag flag, int d, int strLen, char *in_ten)
{
	if (flag.zero)
	{
		while (flag.shir > 0 && flag.shir > flag.dot)
		{
			write(1, "0", 1);
			flag.shir--;
			d++;
		}
	}
	write(1, "0x", 2);
	while (flag.dot > strLen)
	{
		write(1, "0", 1);
		flag.dot--;
		flag.shir++;
		d++;
	}
	write(1, in_ten, strLen);
	d = d + 2 + strLen;
	return (d);
}

static int	unshir(t_flag flag, int d, int strLen, char *in_ten)
{
	while (flag.dot > strLen)
	{
		write(1, "0", 1);
		flag.dot--;
		flag.shir++;
		d++;
	}
	write(1, "0x", 2);
	write(1, in_ten, strLen);
	d = d + 2 + strLen;
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

int	ft_p(int d, size_t i, char **p, t_flag flag)
{
	char	*in_ten;
	int		strLen;

	if (!i)
		return (ft_p_null(d, p, flag));
	if (flag.shir > 2)
		flag.shir -= 2;
	else
		flag.shir = 0;
	if (flag.dot < 0)
		flag.dot_ex = 0;
	(*p)++;
	in_ten = ft_ptoa(i);
	strLen = ft_strlen(in_ten);
	if (flag.dot_ex && flag.dot == 0 && i == 0)
		strLen = flag.dot;
	d = ft_prodolg(flag, d, strLen, in_ten);
	return (d);
}
