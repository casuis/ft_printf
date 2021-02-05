/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2021/02/05 01:20:50 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag			*ft_sconv(char *str, va_list ap)
{
	int			i;
	t_flag		*fl;

	i = -1;
	fl = ft_create_flag_buffer();
	while (str[++i] != ' ' && str[i] && fl->conv == ' ')
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			fl->conv = ft_send_conv(str[i]);
	if (fl->conv != ' ')
		return (ft_parse_flag_core(str, fl, ap));
	return (fl);
}

static size_t			ft_count_add(t_flag *fl, size_t count)
{
	if (fl->ret_count > 0)
		count += fl->ret_count;
	return (count);
}

size_t					ft_end(size_t count, char *str)
{
	free(str);
	return (count);
}

size_t					ft_core(char *str, va_list ap)
{
	int			i;
	size_t		count;
	t_flag		*fl;
	char		*tmp;

	i = -1;
	count = 0;
	str = ft_protect_str(str);
	tmp = str;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			fl = ft_sconv(&str[i + 1], ap);
			if (fl->conv != ' ')
			{
				str = ft_flag_position(&str[++i], fl, ap);
				i = 0;
			}
			count = ft_count_add(fl, count);
		}
		else if (str[i] != '%' && str[i] != '\0')
			count += ft_putchar(str[i]);
	}
	return (ft_end(count, tmp));
}

int						ft_printf(char *str, ...)
{
	va_list		ap;
	size_t		ret;

	ret = 0;
	va_start(ap, str);
	ret = ft_core(str, ap);
	va_end(ap);
	return (ret);
}
