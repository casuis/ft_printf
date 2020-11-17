/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:07:44 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 01:58:41 by asimon           ###   ########.fr       */
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
	int		min_size;
	int		max_size;
	int		count;
	int		count_conv;
	int		is_a_minus;
	size_t	ret_count;
	char	conv;
	char	*ret_conv;
}					t_flag;

typedef struct		s_struct
{
	t_flag	*flag_info;
	int		last_one;
}					t_struct;

size_t		ft_putchar(char c);
size_t		ft_putstr(char *str);
size_t		ft_count(unsigned int nb, int base);
size_t		ft_strlen(char *str);
char		*ft_create(int len);
int		ft_power(int nb, int power);
char		*ft_lower_case(char *str);
char		*ft_upper_case(char *str);
int		ft_atoi(char *str);
char		*ft_itoa(int nb);
t_flag		*ft_convert_c(char c, t_flag *flag_buffer);
t_flag		*ft_convert_d(int nb, t_flag *flag_buffer);
t_flag		*ft_convert_i(int str, t_flag *flag_buffer);
t_flag		*ft_convert_p(void *p, t_flag *flag_buffer);
t_flag		*ft_convert_pourc(t_flag *flag_buffer);
t_flag		*ft_convert_s(char *str, t_flag *flag_buffer);
t_flag		*ft_convert_u(unsigned int nb, t_flag *flag_buffer);
t_flag		*ft_convert_x(unsigned int ptr, t_flag *flag_buffer);
t_flag		*ft_convert_xx(int ptr, t_flag *flag_buffer);
char		*ft_create_table();
void		ft_check_flag(char *str, va_list ap);
int		ft_parse_convert(char *c, va_list ap);
t_flag		*ft_parse_conv(t_flag *flag_buff, va_list ap);
t_flag		*ft_parse_flag_core(char *str, t_flag *buffer, va_list ap);
size_t		ft_flag_spacing(int count, char c);
void		ft_flag_spacing_mark(t_flag *flag_buffer, int min, int max);
char		*ft_flag_position(char *str, t_flag *flag_buffer, va_list ap);
void		ft_flag_minus(t_flag *flag_buffer);
void		ft_flag_mark(t_flag *flag_buffer, va_list ap);
void		ft_flag_star(t_flag *flag_buffer);
void		ft_flag_count_z(t_flag *flag_buffer, char c, va_list ap);
t_flag		*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
char		*ft_protect_str(const char *str);
char		ft_send_conv(char c);
char		ft_find_conv(char *str, t_struct *buffer);
int		ft_print_casu(char *str, t_struct *buffer);
t_struct		*ft_init(int count_arg);
t_flag		*ft_parse_mark_minus(char *str, t_flag *flag_buffer);
t_flag		*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
t_flag		*ft_recup_min_max(char *str, t_flag *flag_buffer);
size_t		ft_read_casu(char *str, va_list ap);
t_flag			*ft_create_flag_buffer();
size_t			ft_mark(t_flag *flag_buffer);
size_t			ft_printf(char *str, ...);

#endif
