/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 11:41:05 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 14:36:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_x(unsigned int ptr, t_flag *flag_buffer)
{
	char		*base;
	char		*buff;
	int			i;
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	i = ft_count(ptr, 16);
	buff = ft_create(i + 1);
	base = "0123456789abcdef";
	while (ptr / 16 > 0)
	{
		buff[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	buff[i] = base[ptr % 16];
	ret->ret_conv = buff;
	ret->count_conv = ft_strlen(buff);
	free(buff);
	return (ret);
}
