/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:18:09 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 14:35:49 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_d(int nb, t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	ret->count_conv = ft_strlen(ft_itoa(nb));
	ret->ret_conv = ft_itoa(nb);
	return (ret);
}