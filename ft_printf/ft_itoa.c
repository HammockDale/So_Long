#include "ft_printf.h"

static void	ft_zapis(char *str, char *s, int i, int k)
{
	while (i > k)
	{
		str[k] = s[i - k - 1];
		k++;
	}
	str[k] = 0;
}

static int	ft_min(int n)
{
	int	m;

	m = 1;
	if (n < 0)
		m = -1;
	return (m);
}

static int	ft_revs(int n, char *s)
{
	size_t	i;

	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	s[12];
	char	*str;
	int		m;
	int		i;
	int		k;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	k = 0;
	m = n * ft_min(n);
	i = ft_revs(m, s);
	if (n < 0)
		i++;
	str = (char *) ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[k++] = '-';
	ft_zapis(str, s, i, k);
	return (str);
}
