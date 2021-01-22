/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:11:54 by user42            #+#    #+#             */
/*   Updated: 2020/12/22 12:47:00 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_xx(unsigned int ptr, t_flag *flag_buffer)
{
	char				*base;
	unsigned char		*buff;
	int					i;

	i = ft_count(ptr, 16);
	buff = (unsigned char *)ft_create(i + 1);
	base = "0123456789abcdef";
	while (ptr / 16 > 0)
	{
		buff[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	buff[i] = base[ptr % 16];
	buff = (unsigned char *)ft_upper_case((char *)buff);
	F_RET_CONV = buff;
	F_CONV_COUNT = ft_strlen(buff);
	return (flag_buffer);
}
