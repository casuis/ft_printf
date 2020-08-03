/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:11:54 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 17:54:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_convert_xx(int ptr)
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
	ret = ft_upper_case(ret);
	ft_putstr(ret);
	free(ret);
}
