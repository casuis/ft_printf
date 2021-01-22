/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:26:52 by user42            #+#    #+#             */
/*   Updated: 2021/01/22 20:54:47 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag		*ft_address(char *str, t_flag *flag_buffer)
{
	int				i;

	i = -1;
	if (!(F_RET_CONV = malloc(sizeof(char) *
	(ft_strlen((unsigned char *)str)))))
		return (NULL);
	if (!(F_PRE = malloc(sizeof(char) * 3)))
		return (NULL);
	if (str)
		F_RET_CONV = (unsigned char *)ft_strcpy(str, (char *)F_RET_CONV);
	else
		F_RET_CONV = (unsigned char *)ft_strcpy("0", (char *)F_RET_CONV);
	F_PRE = ft_strcpy("0x", F_PRE);
	F_CONV_COUNT = ft_strlen(F_RET_CONV);
	free(str);
	str = NULL;
	return (flag_buffer);
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
