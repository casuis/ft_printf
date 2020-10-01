/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:25:25 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 15:24:49 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_flag		*ft_convert_s(char *str, const t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	ret->ret_conv = str;
	ret->count_conv = ft_strlen(str);
	return (ret);
}
