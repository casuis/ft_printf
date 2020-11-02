/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:24 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 22:47:14 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_flag		*ft_convert_c(char c, t_flag *flag_buffer)
{
	t_flag		*ret;
	char		buff[2];

	buff[0] = c;
	buff[1] = '\0';
	ret = (t_flag *)flag_buffer;
	ret->ret_conv = buff;
	ret->count_conv = 1;
	return (ret);
}
