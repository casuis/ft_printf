/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pourc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:44:37 by asimon            #+#    #+#             */
/*   Updated: 2020/11/17 01:27:00 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_pourc(t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = flag_buffer;
	ret->ret_conv = "%";
	ret->count_conv = 1;
	return (ret);
}
