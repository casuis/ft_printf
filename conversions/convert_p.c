/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:26:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/02 16:36:09 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static t_flag		*ft_address(char *str, t_flag *flag_buffer)
{
	int				i;
	int				y;
	char			*ret;

	i = 0;
	y = 4;
	if (!(ret = malloc(sizeof(char) * 15)))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[2] = '7';
	ret[3] = 'f';
	ret[4] = '8';
	while (str[i])
	{
		ret[y] = str[i];
		i++;
		y++;
	}
	ret[y] = '\0';
	flag_buffer->ret_conv = ret;
	free(ret);
	return (flag_buffer);
}

t_flag				*ft_convert_p(void *p, t_flag *flag_buffer)
{
	unsigned long	adr;
	char			*base;
	char			res[11];
	int				i;

	adr = (unsigned long)p;
	base = "0123456789abcdef";
	i = 9;
	while ((adr / 16) > 0 || i >= 9)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	res[10] = '\0';
	return (ft_address(res, flag_buffer));
}
