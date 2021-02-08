/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:43:24 by asimon            #+#    #+#             */
/*   Updated: 2021/02/08 19:07:08 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned char				*ft_fill_blanc_p(t_flag *fl, unsigned char *ret)
{
	int					i;
	int					y;
	unsigned char		*tmp;

	i = 0;
	y = -1;
	tmp = (unsigned char *)"0";
	if (fl->max > 0 || (fl->ret_conv[0] != '0' && fl->ret_conv[1] != '\0'))
	{
		while (i < (fl->max - fl->count_conv))
			ret[i++] = '0';
		ret = ft_strconcat(ret, fl->ret_conv);
		ret[ft_strlen((unsigned char *)ret)] = '\0';
		if (!(fl->ret_conv = malloc(sizeof(unsigned char) * 1)))
			return (NULL);
	}
	ret = ft_strconcat((unsigned char *)fl->prefix, ret);
	if (!(fl->prefix = malloc(sizeof(unsigned char) * 2)))
		return (NULL);
	return (ret);
}
