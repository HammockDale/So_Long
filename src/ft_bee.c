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

int	ft_bee_l1(t_var *var)
{
	ft_grass(var, var->per_x, var->per_y);
	mlx_put_image_to_window(var->mlx, var->win, var->img.bee_L1,
		var->per_x * ONE_SIZE, var->per_y * ONE_SIZE);
	return (0);
}

int	ft_bee_l2(t_var *var)
{
	ft_grass(var, var->per_x, var->per_y);
	mlx_put_image_to_window(var->mlx, var->win, var->img.bee_L2,
		var->per_x * ONE_SIZE, var->per_y * ONE_SIZE);
	return (0);
}

int	ft_bee_l3(t_var *var)
{
	ft_grass(var, var->per_x, var->per_y);
	mlx_put_image_to_window(var->mlx, var->win, var->img.bee_L3,
		var->per_x * ONE_SIZE, var->per_y * ONE_SIZE);
	return (0);
}

int	ft_bee_l4(t_var *var)
{
	ft_grass(var, var->per_x, var->per_y);
	mlx_put_image_to_window(var->mlx, var->win, var->img.bee_L4,
		var->per_x * ONE_SIZE, var->per_y * ONE_SIZE);
	return (0);
}
