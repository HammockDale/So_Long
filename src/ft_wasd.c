/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:59 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:09:01 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	ft_Pup(t_var *var)
{
	if (var->per_y - 1 > 0 && var->map[var->per_y - 1][var->per_x] == '0')
	{
		var->map[var->per_y][var->per_x] = '0';
		var->per_y--;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->per_y - 1 > 0
		&& var->map[var->per_y - 1][var->per_x] == 'C')
	{
		var->score += 1;
		var->map[var->per_y][var->per_x] = '0';
		var->per_y--;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->map[var->per_y - 1][var->per_x] == 'A')
		ft_wrong(var);
	else if (var->per_y - 1 > 0 && var->max_score == var->score
		&& var->map[var->per_y - 1][var->per_x] == 'E')
	{
		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
		ft_close();
	}
	ft_paint(var);
}

void	ft_Pleft(t_var *var)
{
	if (var->per_x - 1 > 0 && var->map[var->per_y][var->per_x - 1] == '0')
	{
		var->map[var->per_y][var->per_x] = '0';
		var->per_x--;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->per_x - 1 > 0
		&& var->map[var->per_y][var->per_x - 1] == 'C')
	{
		var->score += 1;
		var->map[var->per_y][var->per_x] = '0';
		var->per_x--;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->map[var->per_y][var->per_x - 1] == 'A')
		ft_wrong(var);
	else if (var->per_x - 1 > 0 && var->max_score == var->score
		&& var->map[var->per_y][var->per_x - 1] == 'E')
	{
		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
		ft_close();
	}
	ft_paint(var);
}

void	ft_Pdown(t_var *var)
{
	if (var->per_y + 1 < var->size_y
		&& var->map[var->per_y + 1][var->per_x] == '0')
	{
		var->map[var->per_y][var->per_x] = '0';
		var->per_y++;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->per_y + 1 < var->size_y
		&& var->map[var->per_y + 1][var->per_x] == 'C')
	{
		var->score += 1;
		var->map[var->per_y][var->per_x] = '0';
		var->per_y++;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->map[var->per_y + 1][var->per_x] == 'A')
		ft_wrong(var);
	else if (var->per_y + 1 < var->size_y && var->max_score == var->score
		&& var->map[var->per_y + 1][var->per_x] == 'E')
	{
		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
		ft_close();
	}
	ft_paint(var);
}

void	ft_Pright(t_var *var)
{
	if (var->per_x + 1 < var->size_x
		&& var->map[var->per_y][var->per_x + 1] == '0')
	{
		var->map[var->per_y][var->per_x] = '0';
		var->per_x++;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->per_x + 1 < var->size_x
		&& var->map[var->per_y][var->per_x + 1] == 'C')
	{
		var->score += 1;
		var->map[var->per_y][var->per_x] = '0';
		var->per_x++;
		var->map[var->per_y][var->per_x] = 'P';
	}
	else if (var->map[var->per_y][var->per_x + 1] == 'A')
		ft_wrong(var);
	else if (var->per_x + 1 < var->size_x && var->max_score == var->score
		&& var->map[var->per_y][var->per_x + 1] == 'E')
	{
		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
		ft_close();
	}
	ft_paint(var);
}
