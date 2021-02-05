/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:09 by user42            #+#    #+#             */
/*   Updated: 2021/02/05 00:44:01 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_d(int nb, t_flag *fl)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ft_itoa(nb);
	fl->ret_conv = tmp;
	fl->count_conv = ft_strlen((unsigned char *)fl->ret_conv);
	if (fl->ret_conv[0] == '-')
		fl->is_a_minus = 1;
	return (fl);
}
