/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:25:25 by user42            #+#    #+#             */
/*   Updated: 2021/01/22 16:10:51 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_s(char *str, t_flag *flag_buffer)
{
	if (str)
		F_RET_CONV = (unsigned char *)str;
	else
		F_RET_CONV = (unsigned char*)"(null)";
	F_CONV_COUNT = ft_strlen(F_RET_CONV);
	return (flag_buffer);
}
