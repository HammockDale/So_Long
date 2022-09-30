#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	znac;
	int	shir;
	int	zero;
	int	plus;
	int	dot;
	int	dot_ex;
	int	sdvig;
	int	space;
}	t_flag;

int		ft_uxxbp(va_list app, int d, t_flag flag, char **p);
int		ft_csid(va_list app, int d, t_flag flag, char **p);
t_flag	ft_point(va_list app, t_flag flag, char **p);
int		ft_printf(const char *format, ...);
int		ft_c(int d, int c, char **p, t_flag flag);
int		ft_s(int d, char *str, char **p, t_flag flag);
int		ft_i(int d, int i, char **p, t_flag flag);
char	*ft_itoa(int n);
int		ft_s_null(int d, char **p, t_flag flag, int strLen);
char	*ft_utoa(unsigned int n);
int		ft_u(int d, unsigned int i, char **p, t_flag flag);
char	*ft_xtoa(unsigned int n);
int		ft_x(int d, unsigned int i, char **p, t_flag flag);
char	*ft_xbtoa(unsigned int n);
int		ft_xb(int d, int i, char **p, t_flag flag);
int		ft_printchr(char c, int len, int d);
int		ft_p(int d, size_t i, char **p, t_flag flag);
char	*ft_ptoa(size_t n);
int		ft_p_null(int d, char **p, t_flag flag);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	*ft_memset(void *str, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);

#endif
