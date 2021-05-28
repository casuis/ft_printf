/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:27:45 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			ft_flag_spacing_mark(t_flag *fl, int min, int max)
{
	int		count;

	count = 0;
	if (max >= min)
	{
		count = max - fl->count_conv;
		if (fl->is_a_minus == 1)
			ft_putchar('-');
		fl->ret_count += ft_flag_spacing(count, '0');
		fl->ret_count += ft_putstr(fl->ret_conv);
	}
	else if (min > max)
	{
		count = max - fl->count_conv;
		if (max <= 0)
			max = fl->count_conv;
		if (max < fl->count_conv)
			ft_flag_spacing(min - fl->count_conv, ' ');
		else
			fl->ret_count += ft_flag_spacing(min - max, ' ');
		if (fl->is_a_minus == 1)
			fl->ret_count += ft_putchar('-');
		fl->ret_count += ft_flag_spacing(count, '0');
		fl->ret_count += ft_putstr(fl->ret_conv);
	}
}

static void		ft_fbuff(t_flag *fl)
{
	ft_free(fl->ret_conv);
	if (fl->conv == 'p')
		ft_free(fl->prefix);
}

char			*ft_flag_position(char *str, t_flag *fl, va_list ap)
{
	fl = ft_parse_conv(fl, ap);
	if (fl->minus == 1 && fl->star <= 1 && fl->mark != 1)
		fl = ft_flag_minus(fl);
	else if (fl->mark == 1)
		fl = ft_mark(fl);
	else if (fl->zero == 1)
		fl = ft_flag_count_z(fl, '0');
	else if (fl->star == 1 && fl->mark != 1)
		ft_flag_star(fl);
	else if (fl->count > 0)
		fl = ft_flag_count_z(fl, ' ');
	else if (fl->conv == 'c')
		fl->ret_count += ft_putchar(fl->ret_conv[0]);
	else
		fl->ret_count += ft_putstr((unsigned char *)fl->prefix) +
		ft_putstr(fl->ret_conv);
	while ((*str != fl->conv) && *str)
		str++;
	ft_fbuff(fl);
	return (str);
}
