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

static int	ft_revs(size_t n, char *s)
{
	size_t	i;

	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i] = n % 16;
		if (s[i] > 9)
			s[i] = s[i] - 10 + 'a';
		else
			s[i] += '0';
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_ptoa(size_t n)
{
	char	s[12];
	char	*str;
	int		i;
	int		k;

	k = 0;
	i = ft_revs(n, s);
	str = (char *) ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	ft_zapis(str, s, i, k);
	return (str);
}
