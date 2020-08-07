/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:46:19 by asimon            #+#    #+#             */
/*   Updated: 2020/08/07 03:42:33 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_parse_convert(char *c, va_list ap)
{
	int			ret;

	if (*c == 'c')
		ret = ft_convert_c(va_arg(ap, int));
	else if (*c == 'x')
		ret = ft_convert_x(va_arg(ap, int));
	else if (*c == 'X')
		ret = ft_convert_xx(va_arg(ap, int));
	else if (*c == 'u')
		ret = ft_convert_u(va_arg(ap, unsigned int));
	//else if (c == 'p')
		///ret = ft_convert_p(va_arg(ap, void));
	else if (*c == 'd')
		ret = ft_convert_d(va_arg(ap, int));
	else if (*c == 'i')
		ret = ft_convert_i(va_arg(ap, char*));
	else if (*c == 's')
		ret = ft_convert_s(va_arg(ap, char*));
	else
		return (-1);
	return (ret);
}

void		ft_parse_flag(char *c, va_list ap)
{
	if ((*c >='0' && *c <= '9') || (*c == '*') || (*c == '-'))
		ft_check_flag(c, ap);
}
