#include "libft.h"

static int	ft_rev(char *ch, int n)
{
	int		i;
	char	c;

	i = 0;
	if (n == 0)
	{
		ch[0] = '0';
		return (1);
	}
	while (n != 0)
	{
		c = n % 10 + '0';
		n = n / 10;
		ch[i++] = c;
	}
	return (i);
}	

void	ft_putnbr_fd(int n, int fd)
{
	char	ch[12];
	int		i;
	int		k;

	if (fd < 0)
		return ;
	i = 0;
	k = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	i = ft_rev(ch, n);
	while (--i > k - 1)
		write(fd, &ch[i], 1);
}
