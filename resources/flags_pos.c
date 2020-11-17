/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2020/11/17 02:24:18 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_flag_spacing_mark(t_flag *flag_buffer, int min, int max)
{
	int		count;

	count = 0;
	if (max >= min)
	{
		count = max - (flag_buffer->count_conv);
		if (flag_buffer->is_a_minus == 1)
			ft_putchar('-');
		flag_buffer->ret_count += ft_flag_spacing(count, '0');
		flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
	}
	else if (min > max)
	{
		count = max - (flag_buffer->count_conv);
		if (max <= 0)
			max = flag_buffer->count_conv;
		if (max < flag_buffer->count_conv)
			ft_flag_spacing(min - flag_buffer->count_conv, ' ');
		else
			flag_buffer->ret_count += ft_flag_spacing(min - max, ' ');
		if (flag_buffer->is_a_minus == 1)
			flag_buffer->ret_count += ft_putchar('-');
		flag_buffer->ret_count += ft_flag_spacing(count, '0');
		flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
	}
}

char		*ft_flag_position(char *str, t_flag *flag_buffer, va_list ap)
{
	if (flag_buffer->minus == 1 && flag_buffer->star <= 1 &&
	flag_buffer->mark != 1)
		ft_flag_minus(flag_buffer);
	else if (flag_buffer->mark == 1)
		flag_buffer->ret_count += ft_mark(flag_buffer);
	else if (flag_buffer->zero == 1)
		ft_flag_count_z(flag_buffer, '0', ap);
	else if (flag_buffer->star == 1 && flag_buffer->mark != 1)
		ft_flag_star(flag_buffer);
	else if (flag_buffer->count > 0)
		ft_flag_count_z(flag_buffer, ' ', ap);
	else
		flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
	while ((*str != flag_buffer->conv) && *str)
		str++;
	if (*str == '%')
		str++;
	return (str);
}