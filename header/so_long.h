/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:40:24 by hdale             #+#    #+#             */
/*   Updated: 2021/10/04 14:40:26 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include "../minilibx_opengl.tgz/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define BUFFER_SIZE 42
# define  ONE_SIZE 40

# define CHAMOMILE "./xpm/camila.XPM"
# define BEE_L1 "./xpm/BEE/Idle_1_R_1.XPM"
# define BEE_L2 "./xpm/BEE/Idle_1_R_2.XPM"
# define BEE_L3 "./xpm/BEE/Idle_1_R_3.XPM"
# define BEE_L4 "./xpm/BEE/Idle_1_R_4.XPM"
# define BEAR "./xpm/bear.XPM"
# define HORNET_L "./xpm/hornet_L.XPM"
# define HORNET_R "./xpm/hornet_R.XPM"
# define POLE "./xpm/grass.XPM"
# define SOT "./xpm/sot.XPM"
# define BEEHIVE "./xpm/pot.XPM"
# define BEEHIVE "./xpm/pot.XPM"

typedef struct s_data {
	void	*sot;
	void	*grass;
	void	*bee_L1;
	void	*bee_L2;
	void	*bee_L3;
	void	*bee_L4;
	void	*chamomile;
	void	*beehive;
	void	*woll;
	void	*hornet_L;
	void	*hornet_R;
}				t_data;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		per_x;
	int		per_y;
	int		size_x;
	int		size_y;
	char	**map;
	t_data	img;
	int		score;
	int		max_score;
	int		sec;
	char	right;
}				t_var;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
int		ft_new_strjoin(char **line, char **ost);
int		ft_printf(const char *format, ...);
void	ft_init_sprite(t_var *var);
void	ft_chamomile(t_var *var, int m, int n);
int		ft_woll(t_var *var);
int		ft_background(t_var *var);
int		ft_beahive(t_var *var);
int		ft_bear(t_var *var);
int		ft_grass(t_var *var, int x, int y);
int		ft_bee_l1(t_var *var);
int		ft_bee_l2(t_var *var);
int		ft_bee_l3(t_var *var);
int		ft_bee_l4(t_var *var);
void	ft_hornet_L(t_var *var, int m, int n);
void	ft_hornet_R(t_var *var, int m, int n);
void	ft_Pup(t_var *var);
void	ft_Pleft(t_var *var);
void	ft_Pdown(t_var *var);
void	ft_Pright(t_var *var);
int		ft_close(void);
int		ft_error(void);
int		ft_verror(t_var *var);
int		ft_wrong(t_var *var);
void	ft_init_map(t_var *var, int fd, char *str, int i);
void	ft_init_map_last(t_var *var, char *str, int *p, int *ex);
void	ft_try_map(t_var *var, char *ber, int fd, char *str);
void	ft_paint(t_var *var);
void	ft_paint_text(t_var *var);
int		render_next_frame(void *va);
void	ft_move_hornet_right(t_var *var, int m, int n);
void	ft_move_hornet_right(t_var *var, int m, int n);

#endif
