/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:25:25 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:26:30 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_s(char *str, t_flag *fl)
{
	if (str)
	{
		fl->ret_conv = (unsigned char *)ft_create(ft_strlen(
		(unsigned char *)str));
		fl->ret_conv = (unsigned char *)ft_strcpy(
		(const unsigned char *)str, fl->ret_conv);
	}
	else
	{
		fl->ret_conv = (unsigned char *)ft_create(sizeof(unsigned char) * 7);
		fl->ret_conv = ft_strcpy((unsigned char*)"(null)", fl->ret_conv);
	}
	fl->count_conv = ft_strlen(fl->ret_conv);
	return (fl);
}
