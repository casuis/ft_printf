/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:13:36 by asimon            #+#    #+#             */
/*   Updated: 2020/11/16 22:48:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_conv(t_flag *flag_buff, va_list ap)
{
	t_flag		*flag_buffer;

	flag_buffer = (t_flag *)flag_buff;
	if (flag_buffer->conv == 'c')
		flag_buffer = ft_convert_c(va_arg(ap, int), flag_buffer);
	else if (flag_buffer->conv == 'd')
		flag_buffer = ft_convert_d(va_arg(ap, int), flag_buffer);
	else if (flag_buffer->conv == 'i')
		flag_buffer = ft_convert_i(va_arg(ap, int), flag_buffer);
	else if (flag_buffer->conv == 'p')
		flag_buffer = ft_convert_p(va_arg(ap, long int*), flag_buffer);
	else if (flag_buffer->conv == 's')
		flag_buffer = ft_convert_s(va_arg(ap, char*), flag_buffer);
	else if (flag_buffer->conv == 'u')
		flag_buffer = ft_convert_u(va_arg(ap, unsigned int), flag_buffer);
	else if (flag_buffer->conv == 'x')
		flag_buffer = ft_convert_x(va_arg(ap, int), flag_buffer);
	else if (flag_buffer->conv == 'X')
		flag_buffer = ft_convert_xx(va_arg(ap, int), flag_buffer);
	else if (flag_buffer->conv == '%')
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