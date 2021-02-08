/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:01:52 by asimon            #+#    #+#             */
/*   Updated: 2021/02/08 22:26:44 by asimon           ###   ########.fr       */
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
	char			conv;
	int				minus;
	int				mark;
	int				star;
	int				zero;
	int				count;
	int				count_conv;
	int				min;
	int				max;
	int				is_a_minus;
	char			*prefix;
	size_t			ret_count;
	unsigned char	*ret_conv;
}					t_flag;

typedef struct		s_struct
{
	t_flag			*flag_info;
	int				last_one;
}					t_struct;

void				ft_check_flag(char *str, va_list ap);
void				ft_flag_spacing_mark(t_flag *flag_buffer, int min, int max);
void				ft_flag_star(t_flag *flag_buffer);
void				ft_free(void *ptr);

int					ft_power(int nb, int power);
int					ft_atoi(char *str);
int					ft_parse_convert(char *c, va_list ap);
int					ft_print_casu(char *str, t_struct *buffer);
int					ft_printf(char *str, ...);

size_t				ft_putchar(unsigned char c);
size_t				ft_putstr(unsigned char *str);
size_t				ft_count(unsigned long long int nb, int base);
size_t				ft_strlen(unsigned char *str);
size_t				ft_flag_spacing(int count, char c);
size_t				ft_flag_mark(t_flag *flag_buffer, va_list ap);
size_t				ft_core(char *str, va_list ap);

unsigned char		*ft_strcpy(const unsigned char *src, unsigned char *dst);
unsigned char		*ft_strconcat(unsigned char *str, unsigned char *conc);
unsigned char		*ft_fill_blanc_p(t_flag *flag_buffer, unsigned char *ret);

char				*ft_create(int len);
char				*ft_lower_case(char *str);
char				*ft_upper_case(char *str);
char				*ft_itoa(int nb);
char				*ft_create_table();
char				*ft_flag_position(char *str,
t_flag *flag_buffer, va_list ap);
char				*ft_protect_str(char *str);
char				ft_send_conv(char c);
char				ft_find_conv(char *str, t_struct *buffer);

t_flag				*ft_convert_c(unsigned char c, t_flag *flag_buffer);
t_flag				*ft_convert_d(int nb, t_flag *flag_buffer);
t_flag				*ft_convert_i(int str, t_flag *flag_buffer);
t_flag				*ft_convert_p(void *p, t_flag *flag_buffer);
t_flag				*ft_convert_pourc(t_flag *flag_buffer);
t_flag				*ft_convert_s(char *str, t_flag *flag_buffer);
t_flag				*ft_convert_u(unsigned int nb, t_flag *flag_buffer);
t_flag				*ft_convert_x(unsigned int ptr, t_flag *flag_buffer);
t_flag				*ft_convert_xx(unsigned int ptr, t_flag *flag_buffer);
t_flag				*ft_parse_conv(t_flag *flag_buff, va_list ap);
t_flag				*ft_parse_flag_core(char *str, t_flag *buffer, va_list ap);
t_flag				*ft_flag_minus(t_flag *flag_buffer);
t_flag				*ft_flag_count_z(t_flag *flag_buffer, unsigned char c);
t_flag				*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
t_flag				*ft_parse_mark_minus(char *str, t_flag *flag_buffer);
t_flag				*ft_parse_flag_buffer(t_flag *flag_buffer, char *str);
t_flag				*ft_recup_min_max(char *str, t_flag *flag_buffer);
t_flag				*ft_create_flag_buffer();
t_flag				*ft_mark(t_flag *flag_buffer);

t_struct			*ft_init(int count_arg);

#endif
