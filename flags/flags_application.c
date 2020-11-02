/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:13:02 by asimon            #+#    #+#             */
/*   Updated: 2020/11/02 16:20:47 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_flag_minus(t_flag *flag_buffer, va_list ap)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	ft_putstr(flag_buffer->ret_conv);
	if (flag_buffer->star == 1)
		ft_flag_spacing(count, ' ');
	else if (flag_buffer->star == 0)
		ft_flag_spacing(count, ' ');
}

void		ft_flag_count_z(t_flag *flag_buffer, char c, va_list ap)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	if (flag_buffer->star == 1)
		ft_flag_spacing(va_arg(ap, int), c);
	else if (flag_buffer->star == 0)
		ft_flag_spacing(count, c);
	ft_putstr(flag_buffer->ret_conv);
}

void		ft_flag_star(t_flag *flag_buffer, va_list ap)
{
	int			count;
	t_flag		*buffer;
	int			tmp;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	ft_flag_spacing(count, ' ');
	ft_putstr(flag_buffer->ret_conv);
}
