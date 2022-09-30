/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:40:41 by hdale             #+#    #+#             */
/*   Updated: 2021/11/28 02:40:44 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chamomile(t_var *var, int m, int n)
{
	int	c;

	c = 0;
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'C')
			{
				c++;
				mlx_put_image_to_window(var->mlx, var->win,
					var->img.chamomile, n * ONE_SIZE, m * ONE_SIZE);
			}
			m++;
		}		
		m = 0;
		n++;
	}
	if (var->max_score == -1 && c != 0)
		var->max_score = c;
	else if (c == 0 && var->max_score == -1)
		ft_close();
}

void	ft_hornet_L(t_var *var, int m, int n)
{
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'A')
			{
				ft_grass(var, n, m);
				mlx_put_image_to_window(var->mlx, var->win,
					var->img.hornet_L, n * ONE_SIZE, m * ONE_SIZE);
			}
			m++;
		}		
		m = 0;
		n++;
	}
}

void	ft_hornet_R(t_var *var, int m, int n)
{
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'A')
			{
				ft_grass(var, n, m);
				mlx_put_image_to_window(var->mlx, var->win,
					var->img.hornet_R, n * ONE_SIZE, m * ONE_SIZE);
			}
			m++;
		}		
		m = 0;
		n++;
	}
}

int	ft_grass(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img.grass,
		x * ONE_SIZE, y * ONE_SIZE);
	return (0);
}
