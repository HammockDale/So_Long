#include "ft_printf.h"

static int		ft_procent(va_list app, int d, char **p);
static t_flag	ft_begin_flag(t_flag flag, char **p);
static t_flag	ft_flag_init( char **p, va_list app);

int	ft_printf(const char *format, ...)
{
	int				d;
	va_list			app;
	char			*p;

	d = 0;
	va_start(app, format);
	p = (char *) format;
	while (*p)
	{
		while (*p != '%' && *p)
		{
			write(1, &*p, 1);
			p++;
			d++;
		}
		if (*p == '%')
			d = ft_procent(app, d, &p);
	}
	va_end(app);
	return (d);
}

static t_flag	ft_begin_flag(t_flag flag, char **p)
{
	if (**p == '-')
		flag.sdvig = -1;
	else if (**p == '+')
	{
		flag.plus = 1;
		flag.znac = 1;
	}
	else if (**p == '+')
	{
		flag.plus = 1;
		flag.znac = 1;
	}
	else if (**p == ' ')
		flag.space = 1;
	else if (**p == '0')
		flag.zero = 1;
	return (flag);
}

static t_flag	ft_flag_init(char **p, va_list app)
{
	t_flag	flag;

	flag.shir = 0;
	flag.znac = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.dot = 0;
	flag.dot_ex = 0;
	flag.sdvig = 0;
	flag.space = 0;
	while (**p == '0' || **p == '-' || **p == ' ' || **p == '+' || **p == '*')
	{
		flag = ft_begin_flag(flag, p);
		if (**p == '*')
		{
			flag.shir = (int) va_arg(app, int);
			if (flag.shir < 0)
			{
				flag.shir = -flag.shir;
				flag.sdvig = -1;
			}
		}
		(*p)++;
	}
	return (flag);
}

static int	ft_procent(va_list app, int d, char **p)
{
	t_flag	flag;

	(*p)++;
	flag = ft_flag_init(p, app);
	while (ft_isdigit(**p))
	{
		flag.shir = flag.shir * 10 + (**p - '0');
		(*p)++;
	}
	if (**p == '.')
		flag = ft_point(app, flag, p);
	if (**p == 'c' || **p == 's' || **p == 'd' || **p == 'i' || **p == '%')
		d = ft_csid(app, d, flag, p);
	else if (**p == 'u' || **p == 'x' || **p == 'X' || **p == 'p')
		d = ft_uxxbp(app, d, flag, p);
	return (d);
}
