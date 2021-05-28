/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:13:36 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:29:46 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_conv(t_flag *fl, va_list ap)
{
	if (fl->conv == 'c')
		fl = ft_convert_c(va_arg(ap, int), fl);
	else if (fl->conv == 'd')
		fl = ft_convert_d(va_arg(ap, int), fl);
	else if (fl->conv == 'i')
		fl = ft_convert_i(va_arg(ap, int), fl);
	else if (fl->conv == 'p')
		fl = ft_convert_p(va_arg(ap, long int*), fl);
	else if (fl->conv == 's')
		fl = ft_convert_s(va_arg(ap, char*), fl);
	else if (fl->conv == 'u')
		fl = ft_convert_u(va_arg(ap, unsigned int), fl);
	else if (fl->conv == 'x')
		fl = ft_convert_x(va_arg(ap, int), fl);
	else if (fl->conv == 'X')
		fl = ft_convert_xx(va_arg(ap, int), fl);
	else if (fl->conv == '%')
		fl = ft_convert_pourc(fl);
	return (fl);
}

char			ft_send_conv(char c)
{
	if (c == '%')
		return (c);
	else if (c == 'c')
		return (c);
	else if (c == 'x')
		return (c);
	else if (c == 'X')
		return (c);
	else if (c == 'u')
		return (c);
	else if (c == 'p')
		return (c);
	else if (c == 'd')
		return (c);
	else if (c == 'i')
		return (c);
	else if (c == 's')
		return (c);
	else if (!(c <= '9' && c >= '0') && (c != '*') && (c != '.') && (c != '-'))
		return (0);
	return (-1);
}
