/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:43:09 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 15:43:12 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_woll(t_var *var)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == '1' || (var->map[m][n] == 'E' &&
				var->score != var->max_score))
				mlx_put_image_to_window(var->mlx, var->win,
					var->img.woll, n * ONE_SIZE, m * ONE_SIZE);
			else if (var->map[m][n] != '0' && var->map[m][n] != '1' &&
				var->map[m][n] != 'E' && var->map[m][n] != 'P' &&
				var->map[m][n] != 'C' && var->map[m][n] != 'A')
				ft_error();
			m++;
		}		
		m = 0;
		n++;
	}
	return (0);
}

int	ft_beahive(t_var *var)
{
	int	m;
	int	n;
	int	i;

	m = 0;
	n = 0;
	i = 0;
	while (n < var->size_x && var->score == var->max_score)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win,
					var->img.beehive, n * ONE_SIZE, m * ONE_SIZE);
				i++;
			}
			m++;
		}		
		m = 0;
		n++;
	}
	return (0);
}

int	ft_background(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->size_x * ONE_SIZE)
	{
		while (j < var->size_y * ONE_SIZE)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->img.grass, i, j);
			j += ONE_SIZE ;
		}
		j = 0;
		i += ONE_SIZE ;
	}
	return (0);
}

void	ft_init_sprite(t_var *var)
{
	var->img.grass = mlx_xpm_file_to_image(var->mlx, POLE,
			&var->img_width, &var->img_height);
	var->img.bee_L1 = mlx_xpm_file_to_image(var->mlx, BEE_L1,
			&var->img_width, &var->img_height);
	var->img.bee_L2 = mlx_xpm_file_to_image(var->mlx, BEE_L2,
			&var->img_width, &var->img_height);
	var->img.bee_L3 = mlx_xpm_file_to_image(var->mlx, BEE_L3,
			&var->img_width, &var->img_height);
	var->img.bee_L4 = mlx_xpm_file_to_image(var->mlx, BEE_L4,
			&var->img_width, &var->img_height);
	var->img.chamomile = mlx_xpm_file_to_image(var->mlx, CHAMOMILE,
			&var->img_width, &var->img_height);
	var->img.beehive = mlx_xpm_file_to_image(var->mlx, BEEHIVE,
			&var->img_width, &var->img_height);
	var->img.woll = mlx_xpm_file_to_image(var->mlx, SOT,
			&var->img_width, &var->img_height);
	var->img.hornet_L = mlx_xpm_file_to_image(var->mlx, HORNET_L,
			&var->img_width, &var->img_height);
	var->img.hornet_R = mlx_xpm_file_to_image(var->mlx, HORNET_R,
			&var->img_width, &var->img_height);
}
