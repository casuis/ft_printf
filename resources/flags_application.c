/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:13:02 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 20:47:52 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag				*ft_flag_minus(t_flag *flag_buffer)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (F_COUNT) - (F_CONV_COUNT + ft_strlen((unsigned char *)F_PRE));
	if (F_CONV == 'c')
		F_RET_COUNT += ft_putchar(F_RET_CONV[0]);
	else
		F_RET_COUNT += ft_putstr((unsigned char *)F_PRE) +
		ft_putstr(F_RET_CONV);
	if (F_STAR == 1)
		F_RET_COUNT += ft_flag_spacing(count, ' ');
	else if (F_STAR == 0 && count > 0)
		F_RET_COUNT += ft_flag_spacing(count, ' ');
	return (flag_buffer);
}

t_flag				*ft_flag_count_z(t_flag *flag_buffer, unsigned char c)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = F_COUNT - (F_CONV_COUNT + ft_strlen((unsigned char *)F_PRE));
	if (F_IS_A_MINUS == 1 && F_ZERO == 1)
	{
		F_RET_COUNT += ft_putchar('-');
		F_RET_CONV = &(F_RET_CONV[1]);
	}
	F_RET_COUNT += ft_flag_spacing(count, c);
	if (F_CONV == 'p')
		F_RET_COUNT += ft_putstr((unsigned char *)F_PRE);
	if (F_CONV == 'c')
		F_RET_COUNT += ft_putchar(F_RET_CONV[0]);
	else
		F_RET_COUNT += ft_putstr(F_RET_CONV);
	return (flag_buffer);
}

void				ft_flag_star(t_flag *flag_buffer)
{
	int			count;
	t_flag		*buffer;

	buffer = (t_flag *)flag_buffer;
	count = (F_COUNT) - (F_CONV_COUNT);
	F_RET_COUNT += ft_flag_spacing(count, ' ');
	F_RET_COUNT += (ft_putstr((unsigned char *)F_PRE) + ft_putstr(F_RET_CONV));
}
