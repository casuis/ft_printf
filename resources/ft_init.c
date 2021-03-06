/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:27:50 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:27:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_create_flag_buffer(void)
{
	t_flag		*ret;

	if (!(ret = malloc(sizeof(t_flag) * 1)))
		return (NULL);
	ret->prefix = "";
	ret->minus = 0;
	ret->mark = 0;
	ret->star = 0;
	ret->zero = 0;
	ret->min = 0;
	ret->max = 0;
	ret->conv = ' ';
	ret->count = 0;
	ret->ret_count = 0;
	ret->ret_conv = (unsigned char *)"";
	ret->is_a_minus = 0;
	return (ret);
}
