/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2020/09/15 17:46:03 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		ft_send_conv(char c)
{
	if (c == 'c')
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

int			ft_core_conv(t_struct *buffer, char *str)
{
	t_flag		*flag_buffer;
	int			i;

	i = -1;
	flag_buffer = buffer -> flag_info;
	flag_buffer = ft_parse_flag_buffer(flag_buffer, str);
	while (str[++i] != ' ' && str[i])
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			flag_buffer -> conv = ft_send_conv(str[i]);
	if (flag_buffer -> conv != 0)
		return (1);
	return (0);
}

void		ft_read_casu(char *str, t_struct *buff)
{
	while (*str)
	{
		if (*str != '%')
			ft_puchar(*str);
		else if (ft_core_conv(buff, str) == 1)
			ft_parse_conv();
	}
}
