/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 11:41:05 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:26:50 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_x(unsigned int ptr, t_flag *fl)
{
	char				*base;
	unsigned char		*buff;
	int					i;

	i = ft_count(ptr, 16);
	buff = (unsigned char *)ft_create(i + 1);
	base = "0123456789abcdef";
	buff[i] = '\0';
	while (ptr / 16 > 0)
	{
		buff[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	buff[i] = base[ptr % 16];
	fl->ret_conv = buff;
	fl->count_conv = ft_strlen(buff);
	return (fl);
}
