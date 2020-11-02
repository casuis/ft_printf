/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:51:24 by asimon            #+#    #+#             */
/*   Updated: 2020/11/02 16:14:24 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char			*ft_app_fil_blank(t_flag *flag_buffer, char *ret)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	if (flag_buffer->is_a_minus == 1)
		ret[i++] = '-';
	while ((flag_buffer->max_size - flag_buffer->count_conv) > 0)
	{
		ret[i] = '0';
		i++;
		flag_buffer->max_size -= 1;
	}
	while (flag_buffer->ret_conv[y])
	{
		ret[i] = flag_buffer->ret_conv[y];
		i++;
		y++;
	}
	ret[i] = '\0';
	return (ret);
}

static void			ft_app_mark_minus(t_flag *flag_buffer, int count, char *ret)
{
	if (flag_buffer->minus == 1)
	{
		ft_putstr(ret);
		while (count > 0)
		{
			ft_putchar(' ');
			count--;
		}
	}
	else
	{
		while (count > 0)
		{
			ft_putchar(' ');
			count--;
		}
		ft_putstr(ret);
	}
}

void				ft_mark(t_flag *flag_buffer)
{
	char		*ret;
	int			count;
	int			i;
	int			y;

	i = 0;
	y = 0;
	if (flag_buffer->min_size > flag_buffer->max_size)
		count = flag_buffer->min_size;
	else
		count = flag_buffer->max_size;
	count = count + flag_buffer->count_conv;
	ret = ft_create(count);
	ret = ft_app_fil_blank(flag_buffer, ret);
	if (ft_strlen(ret) < flag_buffer->min_size)
		count = flag_buffer->min_size - ft_strlen(ret);
	else
		count = 0;
	ft_app_mark_minus(flag_buffer, count, ret);
	free(ret);
}
