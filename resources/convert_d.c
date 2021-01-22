/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:09 by user42            #+#    #+#             */
/*   Updated: 2020/12/22 12:06:07 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_d(int nb, t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	F_CONV_COUNT = ft_strlen((unsigned char *)ft_itoa(nb));
	F_RET_CONV = (unsigned char *)ft_itoa(nb);
	if (F_RET_CONV[0] == '-')
		F_IS_A_MINUS = 1;
	return (ret);
}
