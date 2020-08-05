/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:07:44 by user42            #+#    #+#             */
/*   Updated: 2020/08/05 14:20:31 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
void		ft_convert_c(char c);
void		ft_convert_d(int nb);
void		ft_convert_i(char *str);
void		ft_convert_p(void *p);
void		ft_convert_s(char *str);
void		ft_convert_u(unsigned int nb);
void		ft_convert_x(int ptr);
void		ft_convert_xx(int ptr);
char		*ft_create_table();

#endif
