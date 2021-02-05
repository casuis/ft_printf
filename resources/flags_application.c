/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:13:02 by asimon            #+#    #+#             */
/*   Updated: 2021/02/05 01:23:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag				*ft_flag_minus(t_flag *fl)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)fl;
	count = (fl->count) - (fl->count_conv + ft_strlen(
	(unsigned char *)fl->prefix));
	if (fl->conv == 'c')
		fl->ret_count += ft_putchar(fl->ret_conv[0]);
	else
		fl->ret_count += ft_putstr((unsigned char *)fl->prefix) +
		ft_putstr(fl->ret_conv);
	if (fl->star == 1)
		fl->ret_count += ft_flag_spacing(count, ' ');
	else if (fl->star == 0 && count > 0)
		fl->ret_count += ft_flag_spacing(count, ' ');
	return (fl);
}

t_flag				*ft_flag_count_z(t_flag *fl, unsigned char c)
{
	int					count;
	t_flag				*buffer;
	unsigned char		*tmp;

	buffer = (t_flag *)fl;
	count = fl->count - (fl->count_conv + ft_strlen(
	(unsigned char *)fl->prefix));
	if (fl->is_a_minus == 1 && fl->zero == 1)
	{
		fl->ret_count += ft_putchar('-');
		fl->ret_conv = &(fl->ret_conv[1]);
	}
	fl->ret_count += ft_flag_spacing(count, c);
	if (fl->conv == 'p')
		fl->ret_count += ft_putstr((unsigned char *)fl->prefix);
	if (fl->conv == 'c')
		fl->ret_count += ft_putchar(fl->ret_conv[0]);
	else
		fl->ret_count += ft_putstr(fl->ret_conv);
	return (fl);
}

void				ft_flag_star(t_flag *fl)
{
	int			count;

	count = (fl->count) - (fl->count_conv);
	fl->ret_count += ft_flag_spacing(count, ' ');
	fl->ret_count += (ft_putstr((unsigned char *)fl->prefix)
	+ ft_putstr(fl->ret_conv));
}
