/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:51:24 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:27:21 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag			*ft_utils_width(t_flag *fl)
{
	if (fl->max < 0 && ((int)ft_strlen(fl->ret_conv) >= -fl->max))
		fl->max = ft_strlen(fl->ret_conv);
	else if (fl->max < 0 && ((int)ft_strlen(fl->ret_conv) < -fl->max))
	{
		fl->max = ft_strlen(fl->ret_conv);
		if (fl->is_a_minus == 1)
			fl->max -= 1;
	}
	return (fl);
}

static char				ft_minus_check(t_flag **fl)
{
	unsigned char		*tmp;

	tmp = (unsigned char *)ft_create(ft_strlen(&(*fl)->ret_conv[1]));
	tmp = ft_strcpy(&(*fl)->ret_conv[1], tmp);
	free((*fl)->ret_conv);
	(*fl)->ret_conv = tmp;
	(*fl)->count_conv -= 1;
	(*fl)->max += 1;
	return ('-');
}

static unsigned char	*ft_app_fill_blank(t_flag *fl,
unsigned char *ret)
{
	int			i;
	int			y;

	i = 0;
	y = -1;
	fl = ft_utils_width(fl);
	if ((fl->max >= 0 && fl->conv == '%') || (fl->max > 0))
	{
		if (fl->is_a_minus == 1)
			ret[i++] = ft_minus_check(&fl);
		if (fl->conv != 's' && fl->conv != 'c')
			while (i < (fl->max - fl->count_conv))
				ret[i++] = '0';
		while (((fl->ret_conv[++y] != '\0' &&
		(fl->conv != 's' && fl->conv != 'c'))
		|| (i < fl->max && fl->ret_conv[y] != '\0')))
			ret[i++] = fl->ret_conv[y];
		ret[i] = '\0';
	}
	else if (fl->max <= 0 && fl->conv == 'd' && fl->ret_conv[0] != '0')
		ret = ft_strcpy(fl->ret_conv, ret);
	return (ret);
}

size_t					ft_app_mark_minus(t_flag *fl,
int count, unsigned char *ret)
{
	size_t		ret_count;

	ret_count = 0;
	if (fl->minus == 1 && (fl->min > 0 || fl->max > 0))
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
	if (fl->conv == 'c' && fl->ret_conv[0] == '\0')
		ret_count += ft_putchar('\0');
	return (ret_count);
}

t_flag					*ft_mark(t_flag *fl)
{
	unsigned char		*ret;
	int					count;

	ret = NULL;
	if (fl->min > fl->max)
		count = fl->min;
	else
		count = fl->max;
	count = count + fl->count_conv;
	ret = (unsigned char *)ft_create(count);
	if (fl->conv != 'p')
		ret = ft_app_fill_blank(fl, ret);
	else
		ret = ft_fill_blanc_p(fl, ret);
	((int)ft_strlen(ret) < fl->min) ? (count = fl->min - ft_strlen(ret))
	: (count = 0);
	count = ft_app_mark_minus(fl, count, ret);
	fl->ret_count += count;
	free(ret);
	return (fl);
}
