#include "ft_printf.h"

int	ft_csid(va_list app, int d, t_flag flag, char **p)
{
	char	*str;
	int		i;

	if (**p == 'c')
	{
		i = (int) va_arg(app, int);
		d = ft_c(d, i, p, flag);
	}
	else if (**p == '%')
		d = ft_s(d, "%", p, flag);
	else if (**p == 's')
	{
		str = (char *) va_arg(app, char *);
		d = ft_s(d, str, p, flag);
	}
	else if (**p == 'i' || **p == 'd')
	{
		i = (int) va_arg(app, int);
		d = ft_i(d, i, p, flag);
	}
	return (d);
}

int	ft_uxxbp(va_list app, int d, t_flag flag, char **p)
{
	unsigned int	u;
	size_t			lu;

	if (**p == 'u')
	{
		u = (unsigned int) va_arg(app, unsigned int);
		d = ft_u(d, u, p, flag);
	}
	else if (**p == 'x')
	{
		u = (unsigned int) va_arg(app, unsigned int);
		d = ft_x(d, u, p, flag);
	}
	else if (**p == 'X')
	{
		u = (unsigned int) va_arg(app, unsigned int);
		d = ft_xb(d, u, p, flag);
	}
	else if (**p == 'p')
	{
		lu = (size_t) va_arg(app, size_t);
		d = ft_p(d, lu, p, flag);
	}
	return (d);
}

t_flag	ft_point(va_list app, t_flag flag, char **p)
{
	(*p)++;
	flag.dot_ex = 1;
	if (**p == '*')
	{
		flag.dot = (int) va_arg(app, int);
		(*p)++;
	}
	else
	{
		while (ft_isdigit(**p))
		{
			flag.dot = flag.dot * 10 + (**p - '0');
			(*p)++;
		}
	}
	return (flag);
}
