/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:25:25 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 14:36:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_s(char *str, t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	ret->ret_conv = str;
	ret->count_conv = ft_strlen(str);
	return (ret);
}
