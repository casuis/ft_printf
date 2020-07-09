/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 01:30:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/09 02:36:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *str, ...)
{
	unsigned int	i;
	unsigned int	y;
	va_list		ap;
	void		*tmp;

	i = 0;
	y = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				y++;
			if (str[i + 1] == 'x')
				y++;
			if (str[i + 1] == 'X')
				y++;
			if (str[i + 1] == 'u')
				y++;
			/*if (str[i + 1] == 'p')
				y++;
			*/if (str[i + 1] == 'd')
				y++;
			if (str[i + 1] == 'i')
				y++;
			if (str[i + 1] == 's')
				y++;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				ft_convert_c(va_arg(ap, char));
			if (str[i + 1] == 'x')
				ft_convert_x(va_arg(ap, int));
			if (str[i + 1] == 'X')
				ft_convert_xx(va_arg(ap, int));
			if (str[i + 1] == 'u')
				ft_convert_u(va_arg(ap, unsigned int));
			/*if (str[i + 1] == 'p')
				ft_convert_p(va_arg(ap, void));
			*/if (str[i + 1] == 'd')
				ft_convert_d(va_arg(ap, int));
			if (str[i + 1] == 'i')
				ft_convert_i(va_arg(ap, char*));
			if (str[i + 1] == 's')
				ft_convert_s(va_arg(ap, char*));
		}
		i++;
	}
}
