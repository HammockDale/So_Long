#include "libft.h"

static void	ft_clean(char **mass, size_t k)
{
	while (k > 0)
	{
		free(mass[k]);
		k--;
	}
	free(mass);
}

static char	**ft_mass(size_t r, char c, char **mass, char *str)
{
	size_t	i;
	size_t	n;
	size_t	k;

	i = 0;
	n = 0;
	k = 0;
	while (k < r)
	{
		while (str[i] == c)
			str++;
		while (str[n] && str[n] != c)
			n++;
		mass[k] = ft_substr(str, 0, n);
		if (!mass[k])
		{
			ft_clean(mass, k);
			return (0);
		}
		k++;
		str = ft_strchr(str, c);
		str++;
		n = 0;
	}
	return (mass);
}

static char	**ft_callmass(size_t len, char c, char *str, size_t *r)
{
	char	**mass;
	size_t	i;

	i = 0;
	mass = NULL;
	while (str[i + 1] && (i + 1) < len)
	{
		if (len > 0 && str[i] == c && str[i + 1] != c)
			(*r)++;
		i++;
	}
	if (len > 0)
		(*r)++;
	mass = (char **) ft_calloc(sizeof(char *), (*r + 1));
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	char	*str;
	size_t	r;
	size_t	len;

	if (!s)
		return (NULL);
	r = 0;
	str = (char *) s;
	while (*str == c && c)
		str++;
	len = ft_strlen(str);
	while (len && str[len - 1] == c)
		len--;
	mass = ft_callmass(len, c, str, &r);
	if (!mass)
		return (NULL);
	return (ft_mass(r, c, mass, str));
}
