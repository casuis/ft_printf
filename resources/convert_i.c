/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:25:59 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char					*ft_parse(unsigned char *str)
{
	if (str[0] == '0' && str[1] != 'x')
		return ("01234567");
	else if (str[0] == '0' && str[1] == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789");
}

static t_flag				*ft_conv_o(unsigned char *str, t_flag *flag_buffer)
{
	int			tmp;
	int			i;
	t_flag		*ret;

	tmp = 0;
	ret = (t_flag *)flag_buffer;
	i = ft_strlen((unsigned char *)str) - 1;
	while (i > 0)
	{
		tmp += ft_power(8, i) * (*str - 48);
		i--;
		str++;
	}
	tmp += *str - 48;
	ret->ret_conv = (unsigned char *)ft_itoa(tmp);
	ret->count_conv = ft_strlen((unsigned char *)ft_itoa(tmp));
	return (ret);
}

static t_flag				*ft_conv_h(
char *base, unsigned char *str, t_flag *flag_buffer)
{
	int			i;
	int			tmp;
	int			y;
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	i = 0;
	y = ft_strlen((unsigned char *)str) - 1;
	tmp = 0;
	str = (unsigned char *)ft_lower_case((char *)str);
	while (y > 0)
	{
		while (*str != base[i])
			i++;
		tmp += ft_power(16, y) * i;
		i = 0;
		y--;
		str++;
	}
	while (*str != base[i])
		i++;
	tmp += i;
	ret->count_conv = ft_strlen((unsigned char *)ft_itoa(tmp));
	ret->ret_conv = (unsigned char *)ft_itoa(tmp);
	return (ret);
}

static unsigned char		*ft_mouv(unsigned char *str, t_flag *flag_buffer)
{
	unsigned char		*ret_buff;
	unsigned char		*tmp;

	ret_buff = str;
	if (*str == '-' || *str == '+')
	{
		if (*ret_buff == '-')
			flag_buffer->is_a_minus = 1;
		ret_buff++;
		if (*ret_buff == '+' && *ret_buff != *(ret_buff - 1))
			ret_buff++;
	}
	tmp = (unsigned char *)ft_create(ft_strlen(ret_buff));
	tmp = ft_strcpy(ret_buff, tmp);
	ft_free(str);
	str = tmp;
	return (str);
}

t_flag						*ft_convert_i(int nb, t_flag *fl)
{
	int					i;
	unsigned char		*tmp;

	i = 0;
	tmp = (unsigned char *)ft_itoa(nb);
	tmp = ft_mouv(tmp, fl);
	if (*tmp == '0' && *(tmp + 1))
		tmp++;
	if (*tmp == 'x' || *tmp == 'X')
		tmp++;
	if (ft_strlen((unsigned char *)ft_parse(tmp)) == 8)
		fl = ft_conv_o(tmp, fl);
	else if (ft_strlen((unsigned char *)ft_parse(tmp)) == 16)
		fl = ft_conv_h(ft_parse(tmp), tmp, fl);
	else if (ft_strlen((unsigned char *)ft_parse(tmp)) == 10)
		fl->ret_conv = (unsigned char *)tmp;
	if (fl->is_a_minus == 1)
	{
		i = -ft_atoi((char *)fl->ret_conv);
		free(fl->ret_conv);
		fl->ret_conv = (unsigned char *)ft_itoa(i);
	}
	fl->count_conv = ft_strlen(fl->ret_conv);
	return (fl);
}
