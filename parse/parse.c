/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:46:19 by asimon            #+#    #+#             */
/*   Updated: 2020/08/06 16:38:26 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_parse_convert(char *c, va_list ap)
{
	if (*c == 'c')
		ft_convert_c(va_arg(ap, int));
	else if (*c == 'x')
		ft_convert_x(va_arg(ap, int));
	else if (*c == 'X')
		ft_convert_xx(va_arg(ap, int));
	else if (*c == 'u')
		ft_convert_u(va_arg(ap, unsigned int));
	/*else if (c == 'p')
		ft_convert_p(va_arg(ap, void));*/
	else if (*c == 'd')
		ft_convert_d(va_arg(ap, int));
	else if (*c == 'i')
		ft_convert_i(va_arg(ap, char*));
	else if (*c == 's')
		ft_convert_s(va_arg(ap, char*));
	else
		return (0);
	return (1);
}

void		ft_parse_flag(char *c, va_list ap)
{
	if ((*c >='0' && *c <= '9') || (*c == '*') || (*c == '-'))
		ft_check_flag(c, ap);
}
