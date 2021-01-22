/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:51:24 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 20:52:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag			*ft_utils_width(t_flag *flag_buffer)
{
	if (F_WIDTH_MAX < 0 && ((int)ft_strlen(F_RET_CONV) > -F_WIDTH_MAX))
		F_WIDTH_MAX = ft_strlen(F_RET_CONV);
	else if (F_WIDTH_MAX < 0 && ((int)ft_strlen(F_RET_CONV) < -F_WIDTH_MAX))
	{
		F_WIDTH_MAX = ft_strlen(F_RET_CONV);
		if (F_IS_A_MINUS == 1)
			F_WIDTH_MAX -= 1;
	}
	return (flag_buffer);
}

static unsigned char	*ft_app_fil_blank(t_flag *flag_buffer,
unsigned char *ret)
{
	int			i;
	int			y;

	i = 0;
	y = -1;
	flag_buffer = ft_utils_width(flag_buffer);
	if (F_WIDTH_MAX > 0)
	{
		if (F_IS_A_MINUS == 1)
		{
			ret[i++] = '-';
			F_RET_CONV = &(F_RET_CONV[1]);
			F_CONV_COUNT -= 1;
			F_WIDTH_MAX += 1;
		}
		if (F_CONV != 's' && F_CONV != 'c')
			while (i < (F_WIDTH_MAX - F_CONV_COUNT))
				ret[i++] = '0';
		while (((F_RET_CONV[++y] != '\0' && (F_CONV != 's' && F_CONV != 'c'))
		|| (i < F_WIDTH_MAX && F_RET_CONV[y] != '\0')))
			ret[i++] = F_RET_CONV[y];
		ret[i] = '\0';
	}
	return (ret);
}

size_t					ft_app_mark_minus(t_flag *flag_buffer,
int count, unsigned char *ret)
{
	size_t		ret_count;

	ret_count = 0;
	if (F_MINUS == 1 && (F_WIDTH_MIN > 0 || F_WIDTH_MAX > 0))
	{
		ret_count += (ft_putstr(ret) + count);
		while (count-- > 0)
			ft_putchar(' ');
	}
	else
	{
		ret_count += count;
		while (count-- > 0)
			ft_putchar(' ');
		ret_count += ft_putstr(ret);
	}
	return (ret_count);
}

size_t					ft_mark(t_flag *flag_buffer)
{
	unsigned char		*ret;
	int					count;
	int					i;
	int					y;

	i = 0;
	y = 0;
	ret = NULL;
	if (F_WIDTH_MIN > F_WIDTH_MAX)
		count = F_WIDTH_MIN;
	else
		count = F_WIDTH_MAX;
	count = count + F_CONV_COUNT;
	ret = (unsigned char *)ft_create(count);
	if (F_CONV != 'p')
		ret = ft_app_fil_blank(flag_buffer, ret);
	else
		ret = (unsigned char *)ft_fill_blanc_p(flag_buffer, (char *)ret);
	((int)ft_strlen(ret) < F_WIDTH_MIN) ? (count = F_WIDTH_MIN - ft_strlen(ret))
	: (count = 0);
	count = ft_app_mark_minus(flag_buffer, count, ret);
	if (F_CONV == 'X' || F_CONV == 'x')
		free(F_RET_CONV);
	free(ret);
	return (count);
}
