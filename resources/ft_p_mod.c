/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:43:24 by asimon            #+#    #+#             */
/*   Updated: 2021/01/25 13:23:38 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char				*ft_fill_blanc_p(t_flag *fl, char *ret)
{
	int			i;
	int			y;
	char		*tmp;

	i = 0;
	y = -1;
	tmp = "0";
	if (fl->max > 0 || (fl->ret_conv[0] != '0' && fl->ret_conv[1] != '\0'))
	{
		while (i < (fl->max - fl->count_conv))
			ret[i++] = '0';
		ret = ft_strconcat(ret, (char *)fl->ret_conv);
		ret[ft_strlen((unsigned char *)ret)] = '\0';
	}
	ret = ft_strconcat(fl->prefix, ret);
	return (ret);
}
