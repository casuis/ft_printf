/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 16:23:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_flag_spacing_mark(t_flag *flag_buffer, int min, int max)
{
	int		count;

	count = 0;
	if (max >= min)
	{
		count = max - F_CONV_COUNT;
		if (F_IS_A_MINUS == 1)
			ft_putchar('-');
		F_RET_COUNT += ft_flag_spacing(count, '0');
		F_RET_COUNT += ft_putstr(F_RET_CONV);
	}
	else if (min > max)
	{
		count = max - F_CONV_COUNT;
		if (max <= 0)
			max = F_CONV_COUNT;
		if (max < F_CONV_COUNT)
			ft_flag_spacing(min - F_CONV_COUNT, ' ');
		else
			F_RET_COUNT += ft_flag_spacing(min - max, ' ');
		if (F_IS_A_MINUS == 1)
			F_RET_COUNT += ft_putchar('-');
		F_RET_COUNT += ft_flag_spacing(count, '0');
		F_RET_COUNT += ft_putstr(F_RET_CONV);
	}
}

char		*ft_flag_position(char *str, t_flag *flag_buffer, va_list ap)
{
	flag_buffer = ft_parse_conv(flag_buffer, ap);
	if (F_MINUS == 1 && F_STAR <= 1 && F_MARK != 1)
		flag_buffer = ft_flag_minus(flag_buffer);
	else if (F_MARK == 1)
		F_RET_COUNT += ft_mark(flag_buffer);
	else if (F_ZERO == 1)
		flag_buffer = ft_flag_count_z(flag_buffer, '0');
	else if (F_STAR == 1 && F_MARK != 1)
		ft_flag_star(flag_buffer);
	else if (F_COUNT > 0)
		flag_buffer = ft_flag_count_z(flag_buffer, ' ');
	else if (F_CONV == 'c')
		F_RET_COUNT += ft_putchar(F_RET_CONV[0]);
	else
		F_RET_COUNT += ft_putstr((unsigned char *)F_PRE) + ft_putstr(F_RET_CONV);
	while ((*str != F_CONV) && *str)
		str++;
	if (F_CONV == '%')
		free(F_RET_CONV);
	return (str);
}
