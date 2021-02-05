/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:24 by user42            #+#    #+#             */
/*   Updated: 2021/01/26 20:17:09 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_c(unsigned char c, t_flag *flag_buffer)
{
	unsigned char		*buff;

	buff = (unsigned char *)ft_create(1);
	buff[0] = c;
	buff[1] = '\0';
	flag_buffer->ret_conv = buff;
	flag_buffer->count_conv = 1;
	return (flag_buffer);
}
