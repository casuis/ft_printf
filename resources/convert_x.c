/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 11:41:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/22 20:46:08 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_x(unsigned int ptr, t_flag *flag_buffer)
{
	char				*base;
	unsigned char		*buff;
	int					i;

	i = ft_count(ptr, 16);
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	base = "0123456789abcdef";
	buff[i + 1] = '\0';
	while (ptr / 16 > 0)
	{
		buff[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	buff[i] = base[ptr % 16];
	F_RET_CONV = buff;
	F_CONV_COUNT = ft_strlen(buff);
	return (flag_buffer);
}
