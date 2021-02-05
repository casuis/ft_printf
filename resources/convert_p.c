/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:26:52 by user42            #+#    #+#             */
/*   Updated: 2021/01/26 20:04:07 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag		*ft_address(char *str, t_flag *fl)
{
	int				i;

	i = -1;
	if (!(fl->ret_conv = malloc(sizeof(char) *
	(ft_strlen((unsigned char *)str)))))
		return (NULL);
	if (!(fl->prefix = malloc(sizeof(char) * 3)))
		return (NULL);
	if (str)
		fl->ret_conv = (unsigned char *)ft_strcpy(
		(unsigned char *)str, fl->ret_conv);
	else
		fl->ret_conv = (unsigned char *)ft_strcpy(
		(unsigned char *)"0", fl->ret_conv);
	fl->prefix = (char *)ft_strcpy(
	(unsigned char *)"0x", (unsigned char *)fl->prefix);
	fl->count_conv = ft_strlen(fl->ret_conv);
	free(str);
	str = NULL;
	return (fl);
}

t_flag				*ft_convert_p(void *p, t_flag *flag_buffer)
{
	unsigned long long	adr;
	char				*base;
	char				*res;
	int					i;

	adr = (unsigned long long)p;
	base = "0123456789abcdef";
	i = ft_count(adr, 16);
	if (!(res = malloc(sizeof(char) * i)))
		return (NULL);
	res[i] = '\0';
	if (adr != 0)
	{
		while ((adr / 16) > 0 || i >= 0)
		{
			res[i--] = base[(adr % 16)];
			adr /= 16;
		}
		res[i] = base[(adr % 16)];
		return (ft_address(res, flag_buffer));
	}
	return (ft_address(NULL, flag_buffer));
}
