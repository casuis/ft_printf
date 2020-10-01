/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spacing_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2020/10/01 18:06:57 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"


void		ft_flag_spacing(int count, char c)
{
	int		i;

	i = 0;
	if (count > 0)
	{
		while (i > count)
		{
			ft_putchar(c);
			i++;
		}
	}
}

void		ft_flag_spacing_arg(const t_flag *flag_buffer, va_list ap)
{
	int		i;
	int		buff;

	i = 0;
	buff = flag_buffer->count;
	while (i <  buff)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_flag_spacing_mark(const t_flag *flag_buffer, int min, int max)
{
	int		count;

	if (max > min)
	{
		count = (flag_buffer->count_conv) - max;
		ft_flag_spacing(count, '0');
		ft_putstr(flag_buffer->ret_conv);

	}
	if (min > max)
	{
		count = (flag_buffer->count_conv) - min;
		ft_flag_spacing(min - max, ' ');
		ft_flag_spacing(count, '0');
		ft_putstr(flag_buffer->ret_conv);
	}
}

void		ft_flag_position(char *str, const t_flag *flag_buffer, va_list ap)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (flag_buffer->count) - (flag_buffer->count_conv);
	if (flag_buffer->minus == 1)
	{
		ft_putstr(flag_buffer->ret_conv);
		if (flag_buffer->star == 1)
			ft_flag_spacing(va_arg(ap, int), ' ');
		else if (flag_buffer->star == 0)
			ft_flag_spacing(count, ' ');
	}
	else if (flag_buffer->mark == 1)
	{
		if (flag_buffer->star > 0)
			ft_flag_spacing_mark(flag_buffer, va_arg(ap, int), va_arg(ap, int));
		else if (flag_buffer->star < 0)
			flags_spacing_mark(flag_buffer, flag_buffer->min_size, flag_buffer-> max_size);
	}

}
