/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2021/01/22 20:53:14 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char			*ft_parse(char *str)
{
	if (str[0] == '0' && str[1] != 'x')
		return ("01234567");
	else if (str[0] == '0' && str[1] == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789");
}

static t_flag		*ft_conv_o(char *str, t_flag *flag_buffer)
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

static t_flag		*ft_conv_h(char *base, char *str, t_flag *flag_buffer)
{
	int			i;
	int			tmp;
	int			y;
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	i = 0;
	y = ft_strlen((unsigned char *)str) - 1;
	tmp = 0;
	str = ft_lower_case(str);
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

char				*ft_mouv(char *str, t_flag *flag_buffer)
{
	t_flag		*buff;

	buff = (t_flag *)flag_buffer;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			F_IS_A_MINUS = 1;
		str++;
		if (*str == '+' && *str != *(str - 1))
			str++;
	}
	return (str);
}

t_flag				*ft_convert_i(int str, t_flag *flag_buffer)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_itoa(str);
	tmp = ft_mouv(tmp, flag_buffer);
	if (*tmp == '0' && *(tmp + 1))
		tmp++;
	if (*tmp == 'x' || *tmp == 'X')
		tmp++;
	if (ft_strlen((unsigned char *)ft_parse(tmp)) == 8)
		return (ft_conv_o(tmp, flag_buffer));
	else if (ft_strlen((unsigned char *)ft_parse(tmp)) == 16)
		return (ft_conv_h(ft_parse(tmp), tmp, flag_buffer));
	else if (ft_strlen((unsigned char *)ft_parse(tmp)) == 10)
		F_RET_CONV = (unsigned char *)tmp;
	if (F_IS_A_MINUS == 1)
		F_RET_CONV = (unsigned char *)ft_itoa(-(ft_atoi((char *)F_RET_CONV)));
	F_CONV_COUNT = ft_strlen(F_RET_CONV);
	return (flag_buffer);
}
