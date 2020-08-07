/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2020/08/07 03:47:23 by asimon           ###   ########.fr       */
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

size_t			ft_convert_octal(char *str, char *base)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		tmp += ft_power(8, i) * (*str - 48);
		i--;
		str++;
	}
	tmp += *str - 48;
	ft_putstr(ft_itoa(tmp));
	return (ft_strlen(ft_itoa(tmp)));
}

size_t			ft_convert_hexa(char *base, char *str)
{
	int	i;
	int	tmp;
	int	y;

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
	ft_putstr(ft_itoa(tmp));
	return (ft_strlen(ft_itoa(tmp)));
}

size_t			ft_convert_i(char *str)
{
	char	*base;
	int		nb;
	int		i;

	i = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ft_putchar('-');
		str++;
		if ((*str == '+' || *str == '-') && *str != *(str - 1))
			str++;
	}
	base = ft_parse(str);
	if (*str == '0' && *(str + 1))
		str++;
	if (*str == 'x' || *str == 'X')
		str++;
	if (ft_strlen(base) == 8)
		return (ft_convert_octal(str, base));
	else if (ft_strlen(base) == 16)
		return (ft_convert_hexa(base, str));
	else if (ft_strlen(base) == 10)
		ft_putstr(str);
	return (ft_strlen(str));
}
