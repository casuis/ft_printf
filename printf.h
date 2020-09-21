/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:07:44 by user42            #+#    #+#             */
/*   Updated: 2020/09/21 10:03:38 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_flag
{
	int		minus;
	int		mark;
	int		star;
	int		zero;
	char	conv;
	int		min_size;
	int		max_size;
	size_t	count;
}					t_flag;

typedef struct		s_struct
{
	t_flag	*flag_info;
	char	*ret;
	int		last_one;
}					t_struct;

void		ft_putchar(char c);
void		ft_putstr(char *str);
size_t		ft_count(int nb, int base);
size_t		ft_strlen(char *str);
char		*ft_create(int len);
int		ft_power(int nb, int power);
char		*ft_lower_case(char *str);
char		*ft_upper_case(char *str);
int		ft_atoi(char *str);
char		*ft_itoa(int nb);
size_t		ft_convert_c(char c);
size_t		ft_convert_d(int nb);
size_t		ft_convert_i(char *str);
size_t		ft_convert_p(void *p);
size_t		ft_convert_s(char *str);
size_t		ft_convert_u(unsigned int nb);
size_t		ft_convert_x(int ptr);
size_t		ft_convert_xx(int ptr);
char		*ft_create_table();
void		ft_check_flag(char *str, va_list ap);
int		ft_parse_convert(char *c, va_list ap);
void		ft_flag_spacing(char *str, int count, char c);
void		ft_flag_spacing_arg(const t_flag *flag_buffer);
void		ft_flag_position(const t_flag *flag_buffer, char *str);
void		ft_parse_flag(t_struct *buff);
t_flag		*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
char		ft_send_conv(char c);
char		ft_find_conv(char *str, t_struct *buffer);
int			ft_print_casu(char *str, t_struct *buffer);
t_struct		*ft_init(int count_arg);
t_flag		*ft_parse_mark_minus(char *str, t_flag *flag_buffer);
t_flag		*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
t_flag		*ft_recup_min_max(char *str, const t_flag *flag_buffer);

#endif
