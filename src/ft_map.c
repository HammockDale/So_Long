/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:43 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:08:45 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_last(t_var *var, char *str, int *p, int *ex)
{
	if (var->size_x != (int)ft_strlen(var->map[*p]))
		ft_verror(var);
	if (var->map[*p][0] != '1' || var->map[*p][var->size_x - 1] != '1')
		ft_verror(var);
	if (ft_strchr(var->map[*p], 'E'))
		*ex = 1;
	str = ft_strchr(var->map[*p], 'P');
	if (str)
	{
		if (var->per_y >= 0)
			ft_verror(var);
		var->per_y = *p;
		var->per_x = (str - var->map[*p]);
	}
}

void	ft_init_map(t_var *var, int fd, char *str, int i)
{
	int	p;
	int	ex;

	p = 0;
	var->per_y = -1;
	var->score = 0;
	ex = 0;
	var->map = ft_calloc(sizeof(size_t), var->size_y);
	if (!var->map)
		ft_error();
	i = get_next_line(fd, &(var->map[p]));
	while (fd > 0 && (i > 0))
	{
		ft_init_map_last(var, str, &p, &ex);
		i = get_next_line(fd, &(var->map[++p]));
	}
	if (i < 0 || fd < 0 || var->per_y < 0 || ex == 0)
		ft_verror(var);
	if (ft_strnchr(var->map[0], '1'))
		ft_verror(var);
	if (ft_strnchr(var->map[var->size_y - 1], '1'))
		ft_verror(var);
}

void	ft_try_map(t_var *var, char *ber, int fd, char *str)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	str = ft_strrchr(ber, '.');
	if (!str || str[1] != 'b' || str[2] != 'e' || str[3] != 'r' || str[4])
		ft_error();
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		ft_error();
	i = get_next_line(fd, &str);
	while (i >= 0)
	{
		k++;
		var->size_x = ft_strlen(str);
		free(str);
		i = get_next_line(fd, &str);
		if (!i)
			break ;
	}
	if (i < 0)
		ft_error();
	free(str);
	var->size_y = k + 1;
}

void	ft_paint_text(t_var *var)
{
	char	*tmp;
	char	*max;
	char	*str;

	tmp = ft_itoa(var->score);
	str = ft_strjoin("Your score is ", tmp);
	free(tmp);
	max = ft_itoa(var->max_score);
	tmp = ft_strjoin(str, " of ");
	free(str);
	str = ft_strjoin(tmp, max);
	free(max);
	free(tmp);
	mlx_string_put(var->mlx, var->win, 10, var->size_y * ONE_SIZE,
		0x00FFFF00, str);
	free(str);
	if (var->score == var->max_score)
		mlx_string_put(var->mlx, var->win, 10, (var->size_y * ONE_SIZE) + 20,
			0x00FFFF00, "Go out!");
}

void	ft_paint(t_var *var)
{
	mlx_clear_window(var->mlx, var->win);
	ft_background(var);
	ft_beahive(var);
	ft_woll(var);
	ft_chamomile(var, 0, 0);
	if (var->max_score == 0)
		ft_close();
	ft_bee_l1(var);
	ft_hornet_L(var, 0, 0);
	ft_paint_text(var);
}
