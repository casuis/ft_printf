/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:43:24 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 18:41:53 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char				*ft_fill_blanc_p(t_flag *flag_buffer, char *ret)
{
	int			i;
	int			y;
	char		*tmp;

	i = 0;
	y = -1;
	tmp = "0";
	if (F_WIDTH_MAX > 0 || (F_RET_CONV[0] != '0' && F_RET_CONV[1] != '\0'))
	{
		while (i < (F_WIDTH_MAX - F_CONV_COUNT))
			ret[i++] = '0';
		ret = ft_strconcat(ret, (char *)F_RET_CONV);
		ret[ft_strlen((unsigned char *)ret)] = '\0';
	}
	ret = ft_strconcat(F_PRE, ret);
	return (ret);
}