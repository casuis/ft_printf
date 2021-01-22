/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:13:36 by asimon            #+#    #+#             */
/*   Updated: 2021/01/07 13:55:18 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_conv(t_flag *flag_buffer, va_list ap)
{
	if (F_CONV == 'c')
		flag_buffer = ft_convert_c(va_arg(ap, int), flag_buffer);
	else if (F_CONV == 'd')
		flag_buffer = ft_convert_d(va_arg(ap, int), flag_buffer);
	else if (F_CONV == 'i')
		flag_buffer = ft_convert_i(va_arg(ap, int), flag_buffer);
	else if (F_CONV == 'p')
		flag_buffer = ft_convert_p(va_arg(ap, long int*), flag_buffer);
	else if (F_CONV == 's')
		flag_buffer = ft_convert_s(va_arg(ap, char*), flag_buffer);
	else if (F_CONV == 'u')
		flag_buffer = ft_convert_u(va_arg(ap, unsigned int), flag_buffer);
	else if (F_CONV == 'x')
		flag_buffer = ft_convert_x(va_arg(ap, int), flag_buffer);
	else if (F_CONV == 'X')
		flag_buffer = ft_convert_xx(va_arg(ap, int), flag_buffer);
	else if (F_CONV == '%')
		flag_buffer = ft_convert_pourc(flag_buffer);
	return (flag_buffer);
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
