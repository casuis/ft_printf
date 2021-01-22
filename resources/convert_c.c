/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:24 by user42            #+#    #+#             */
/*   Updated: 2020/12/23 15:43:18 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_c(unsigned char c, t_flag *flag_buffer)
{
	unsigned char		buff[2];

	buff[0] = c;
	buff[1] = '\0';
	F_RET_CONV = buff;
	F_CONV_COUNT = 1;
	return (flag_buffer);
}
