/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:35 by hdale             #+#    #+#             */
/*   Updated: 2021/11/11 16:08:37 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	write(1, "The end.\n", 9);
	exit(0);
	return (0);
}

int	ft_error(void)
{
	write(2, "Error!\n", 7);
	exit(1);
	return (1);
}

int	ft_verror(t_var *var)
{
	int	i;

	i = 0;
	while (var->map[i])
		i++;
	while (i >= 0)
	{
		free(var->map[i]);
		i--;
	}
	free(var->map);
	write(2, "Error!\n", 7);
	exit(1);
	return (1);
}

int	ft_wrong(t_var *var)
{
	ft_printf("Your score is %d\n", var->score);
	mlx_destroy_window(var->mlx, var->win);
	write(1, "Game over!\n", 11);
	exit(0);
	return (0);
}
