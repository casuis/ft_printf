/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 16:14:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char		*ft_parse(char *str)
{
	if (str[0] == '0' && str[1] != 'x')
		return ("01234567");
	else if (str[0] == '0' && str[1] == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789");
}

static t_flag		*ft_conv_o(char *str, char *base, const t_flag *flag_buffer)
{
	int		tmp;
	int		i;
	t_flag		*ret;

	tmp = 0;
	ret = (t_flag *)flag_buffer;
	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		tmp += ft_power(8, i) * (*str - 48);
		i--;
		str++;
	}
	tmp += *str - 48;
	ret->ret_conv = ft_itoa(tmp);
	ret->count_conv = ft_strlen(ft_itoa(tmp));
	return (ret);
}

static t_flag		*ft_conv_h(char *base, char *str, const t_flag *flag_buffer)
{
	int	i;
	int	tmp;
	int	y;
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	i = 0;
	y = ft_strlen(str) - 1;
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
	ret->count_conv = ft_strlen(ft_itoa(tmp));
	ret->ret_conv = ft_itoa(tmp);
	return (ret);
}

static char			*ft_mouv(char *str, const t_flag *flag_buffer)
{
	t_flag		*buff;

	buff = (t_flag *)flag_buffer;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			buff->is_a_minus = 1;
		str++;
		if ((*str == '+' || *str == '-') && *str != *(str - 1))
			str++;
	}
	return (str);
}

t_flag			*ft_convert_i(char *str, const t_flag *flag_buffer)
{
	t_flag		*ret;
	int			nb;
	int			i;

	i = 0;
	ret = (t_flag*)flag_buffer;
	str = ft_mouv(str, ret);
	if (*str == '0' && *(str + 1))
		str++;
	if (*str == 'x' || *str == 'X')
		str++;
	if (ft_strlen(ft_parse(str)) == 8)
		return (ft_convert_octal(str, ft_parse(str), ret));
	else if (ft_strlen(ft_parse(str)) == 16)
		return (ft_convert_hexa(ft_parse(str), str, ret));
	else if (ft_strlen(ft_parse(str)) == 10)
		ret->ret_conv = str;
	ret->count_conv = ft_strlen(str);
	return (ret);
}
