/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:13:02 by asimon            #+#    #+#             */
/*   Updated: 2020/11/18 02:40:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_flag_minus(t_flag *flag_buffer)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
	if (flag_buffer->star == 1)
		flag_buffer->ret_count += ft_flag_spacing(count, ' ');
	else if (flag_buffer->star == 0 && count > 0)
		flag_buffer->ret_count += ft_flag_spacing(count, ' ');
}

void		ft_flag_count_z(t_flag *flag_buffer, char c, va_list ap)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	if (flag_buffer->star == 1)
		flag_buffer->ret_count += ft_flag_spacing(va_arg(ap, int), c);
	else if (flag_buffer->star == 0 && count > 0)
	{
		if (flag_buffer->is_a_minus == 1 && flag_buffer->zero == 1)
		{
			flag_buffer->ret_count += ft_putchar('-');
			flag_buffer->ret_conv = &(flag_buffer->ret_conv[1]);
		}
		flag_buffer->ret_count += ft_flag_spacing(count, c);
	}
	flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
}

void		ft_flag_star(t_flag *flag_buffer)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	flag_buffer->ret_count += ft_flag_spacing(count, ' ');
	flag_buffer->ret_count += ft_putstr(flag_buffer->ret_conv);
}
