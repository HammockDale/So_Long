/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:09:26 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:09:37 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_con(char **ost)
{
	free(*ost);
	*ost = NULL;
	return (1);
}

static int	ft_ost(char **line, char **ost, int i, char *p)
{
	char	*new;

	if (*ost)
	{
		new = *ost;
		if (*ost[0] == '\n' && ft_strlen(*ost) == 1)
			return (ft_con(ost));
		p = ft_strchr(new, '\n');
		if (!p)
			return (ft_new_strjoin(line, ost));
		else
		{
			*p++ = 0;
			if (!(*p))
				return (ft_new_strjoin(line, ost) || 1);
			new = ft_strdup(p);
			i = ft_new_strjoin(line, ost);
			if (i < 0 || !new)
				return (-1);
			i = 1;
			*ost = new;
			return (i);
		}
	}
	return (0);
}

static int	ft_prn(char *buf, char **line, char **ost, char *tmp)
{
	char	*p;

	p = ft_strchr(buf, '\n');
	if (p)
	{
		if (buf[0] == '\n' && ft_strlen(buf) == 1)
			return (ft_con(ost));
		*p++ = 0;
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (!(*line))
			return (-1);
		if (*p)
		{
			*ost = ft_strdup(p);
			if (!(*ost))
				return (-1);
		}
		return (1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (0);
}

static int	ft_len_buf(int fd, int len_buf, char **ost, char **line)
{
	int		i;
	char	*buf;

	while (len_buf)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (-1);
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf == 0)
		{
			free(buf);
			return (0);
		}
		buf[len_buf] = 0;
		i = ft_prn(buf, line, ost, buf);
		if (i)
		{
			free(buf);
			return (i);
		}
		free(buf);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			len_buf;
	static char	*ost;

	if ((read(fd, 0, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	len_buf = ft_ost(line, &ost, 0, NULL);
	if (len_buf)
		return (len_buf);
	len_buf = 1;
	return (ft_len_buf(fd, len_buf, &ost, line));
}
