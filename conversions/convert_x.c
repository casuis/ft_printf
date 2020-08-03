/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 11:41:05 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 17:55:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_convert_x(int ptr)
{
	char		*base;
	char		*ret;
	int			i;

	i = ft_count(ptr, 16);
	ret = ft_create(i + 1);
	base = "0123456789abcdef";
	while (ptr / 16 > 0)
	{
		ret[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	ret[i] = base[ptr % 16];
	ft_putstr(ret);
	free(ret);
}
