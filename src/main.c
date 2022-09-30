/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:10:06 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:10:08 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_kb_hook(int keycode, t_var *var)
{
	if (keycode == 13)
		ft_Pup(var);
	else if (keycode == 0)
		ft_Pleft(var);
	else if (keycode == 1)
		ft_Pdown(var);
	else if (keycode == 2)
		ft_Pright(var);
	if (keycode == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		ft_close();
	}
	return (var->score);
}

void	ft_move_hornet_left(t_var *var, int m, int n)
{
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'A')
			{
				if (var->map[m][n - 1] == '0')
				{
					var->map[m][n] = '0';
					var->map[m][n - 1] = 'A';
					ft_paint(var);
				}
				else if (var->map[m][n - 1] == 'P')
					ft_wrong(var);
				else
					ft_hornet_L(var, 0, 0);
			}
			m++;
		}		
		m = 0;
		n++;
	}
}

void	ft_move_hornet_right(t_var *var, int m, int n)
{
	while (n < var->size_x)
	{
		while (m < var->size_y)
		{
			if (var->map[m][n] == 'A')
			{
				if (var->map[m][n + 1] == '0' && var->map[m][n + 2] != 'A')
				{
					var->map[m][n] = '0';
					var->map[m][n + 1] = 'A';
					ft_paint(var);
				}
				else if (var->map[m][n + 1] == 'P')
					ft_wrong(var);
				else
					ft_hornet_L(var, 0, 0);
				n++;
			}
			m++;
		}		
		m = 0;
	}
}

int	render_next_frame(void *va)
{
	t_var	*var;

	var = (t_var *)va;
	var->sec = var->sec % 8000;
	if (var->sec == 0)
	{
		if (var->right == 1)
			ft_move_hornet_right(var, 0, 0);
		else if (var->right == 0)
			ft_move_hornet_left(var, 0, 0);
		ft_bee_l1(var);
	}
	if (var->sec == 2000)
		ft_bee_l2(var);
	if (var->sec == 4000)
	{
		ft_hornet_R(var, 0, 0);
		ft_bee_l3(var);
	}
	if (var->sec == 6000)
		ft_bee_l4(var);
	var->sec++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;
	int		fd;

	if (argc != 2)
		ft_error();
	ft_try_map(&var, argv[1], -1, NULL);
	fd = open(argv[1], O_RDONLY);
	ft_init_map(&var, fd, NULL, 0);
	var.mlx = mlx_init();
	var.max_score = -1;
	ft_init_sprite(&var);
	var.win = mlx_new_window(var.mlx, var.size_x * ONE_SIZE,
			(var.size_y + 1) * ONE_SIZE, "THE GAME!");
	ft_paint(&var);
	mlx_key_hook(var.win, key_kb_hook, &var);
	var.sec = 1;
	var.right = 0;
	mlx_loop_hook(var.mlx, render_next_frame, &var);
	mlx_hook(var.win, 17, 0, ft_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
