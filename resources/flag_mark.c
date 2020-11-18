/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:51:24 by asimon            #+#    #+#             */
/*   Updated: 2020/11/18 03:17:07 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char			*ft_app_fil_blank(t_flag *flag_buffer, char *ret)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	if (flag_buffer->is_a_minus == 1)
	{
		ret[i++] = '-';
		flag_buffer->ret_conv = &(flag_buffer->ret_conv[1]);
		flag_buffer->count_conv -= 1;
		flag_buffer->max_size += 1;
	}
	if (flag_buffer->conv == 'i')
		while (i < (flag_buffer->max_size - flag_buffer->count_conv))
			ret[i++] = '0';
	while ((flag_buffer->conv == 'i' && flag_buffer->ret_conv[y]) ||
	(i < flag_buffer->max_size && flag_buffer->ret_conv[y]))
	{
		ret[i++] = flag_buffer->ret_conv[y];
		y++;
	}
	ret[i] = '\0';
	return (ret);
}

static size_t			ft_app_mark_minus(t_flag *flag_buffer, int count, char *ret)
{
	size_t		ret_count;
	//pb de min size
	printf("flag_buffer->min_size: %d\n", flag_buffer->min_size);
	ret_count = 0;
	if (flag_buffer->minus == 1 && (flag_buffer->min_size > 0
	|| flag_buffer->max_size > 0))
	{
		ret_count += (ft_putstr(ret) + count);
		while (count > 0)
		{
			ft_putchar(' ');
			count--;
		}
	}
	else
	{
		ret_count += count;
		while (count > 0)
		{
			ft_putchar(' ');
			count--;
		}
		ret_count += ft_putstr(ret);
	}
	return (ret_count);
}

size_t				ft_mark(t_flag *flag_buffer)
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
	if ((int)ft_strlen(ret) < flag_buffer->min_size)
		count = flag_buffer->min_size - ft_strlen(ret);
	else
		count = 0;
	count = ft_app_mark_minus(flag_buffer, count, ret);
	free(ret);
	return (count);
}
