/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:11:54 by user42            #+#    #+#             */
/*   Updated: 2020/08/07 02:13:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

size_t		ft_convert_xx(int ptr)
{
	char		*base;
	char		*buff;
	int			i;
	size_t			ret;

	i = ft_count(ptr, 16);
	ret = i;
	buff = ft_create(i + 1);
	base = "0123456789abcdef";
	while (ptr / 16 > 0)
	{
		buff[i] = base[ptr % 16];
		ptr /= 16;
		i--;
	}
	buff[i] = base[ptr % 16];
	buff = ft_upper_case(buff);
	ft_putstr(buff);
	free(buff);
	return (ret);
}
