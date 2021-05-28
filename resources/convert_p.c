/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:26:52 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:26:08 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag		*ft_address(unsigned char *str, t_flag *fl)
{
	if (str)
		fl->ret_conv = (unsigned char *)ft_create(ft_strlen(str) + 1);
	else
		fl->ret_conv = (unsigned char *)ft_create(2);
	fl->prefix = (char *)ft_create(4);
	if (str)
		fl->ret_conv = (unsigned char *)ft_strcpy(
		(unsigned char *)str, fl->ret_conv);
	else
		fl->ret_conv = (unsigned char *)ft_strcpy(
		(unsigned char *)"0", fl->ret_conv);
	fl->prefix = (char *)ft_strcpy(
	(unsigned char *)"0x", (unsigned char *)fl->prefix);
	fl->count_conv = ft_strlen(fl->ret_conv);
	ft_free(str);
	return (fl);
}

t_flag				*ft_convert_p(void *p, t_flag *flag_buffer)
{
	unsigned long long		adr;
	char					*base;
	unsigned char			*res;
	int						i;

	adr = (unsigned long long)p;
	base = "0123456789abcdef";
	i = ft_count(adr, 16);
	if (adr != 0)
	{
		res = (unsigned char *)ft_create(i + 1);
		while ((adr / 16) > 0 || i > 0)
		{
			res[i--] = base[(adr % 16)];
			adr /= 16;
		}
		res[i] = base[(adr % 16)];
		return (ft_address(res, flag_buffer));
	}
	return (ft_address(NULL, flag_buffer));
}
