/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:09:47 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:09:52 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (const char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	s;
	size_t	d;

	d = 0;
	s = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (s + 1));
	if (!str)
		return (NULL);
	while (d < s && src[d])
	{
		str[d] = src[d];
		d++;
	}
	str[d] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = '\0';
	return (str);
}

int	ft_new_strjoin(char **line, char **ost)
{
	char	*tmp;
	char	*new;

	new = *ost;
	tmp = *line;
	*line = ft_strjoin(*line, new);
	if (!(*line))
	{
		free(tmp);
		free(new);
		*ost = NULL;
		return (-1);
	}
	free(tmp);
	if (!(new))
		return (-1);
	free(new);
	*ost = NULL;
	return (0);
}
