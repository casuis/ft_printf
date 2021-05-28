/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:56:04 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:29:31 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_flag_buffer(t_flag *fl, char *str)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '%')
	{
		if (str[i] == '.' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			fl->mark = 1;
		if (str[i] == '-')
			fl->minus = 1;
		if (str[i] == '0' && !(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& (str[i - 1] != '.') && fl->minus != 1)
			fl->zero = 1;
		if (str[i] == '*' && !(str[i - 1] > '0' & str[i - 1] <= '9'))
			fl->star += 1;
		i++;
	}
	if (fl->mark == 0 && fl->zero == 0 && fl->star == 0 && fl->minus == 0)
		fl->count = ft_atoi(str);
	if (fl->minus == 1)
		fl->zero = 0;
	return (fl);
}

t_flag			*ft_parse_mark_minus(char *str, t_flag *fl)
{
	int			i;

	i = 0;
	if (fl->mark == 1 && fl->star == 0)
	{
		if (str[i] == '0')
			while (!(str[i] >= '1' && str[i] <= '9') && str[i] != '.')
				i++;
		fl->min = ft_atoi(&str[i]);
		if (fl->min < 0)
			fl->min = -fl->min;
		while (str[i] != '.')
			i++;
		fl->max = ft_atoi(&str[++i]);
		return (fl);
	}
	else if (!(fl->mark == 1))
	{
		while (!(str[i] >= '0' && str[i] <= '9') && (str[i] && str[i] != ' ')
		&& str[i] != fl->conv)
			i++;
		fl->count = ft_atoi(&str[i]);
		return (fl);
	}
	return (fl);
}

t_flag			*ft_parse_star(char *str, t_flag *fl, va_list ap)
{
	int			i;

	i = -1;
	if (fl->star == 2 && fl->mark == 1)
	{
		fl->min = va_arg(ap, int);
		fl->max = va_arg(ap, int);
	}
	else if (fl->star == 1 && fl->mark == 1)
	{
		while (str[++i] && str[i] != ' ')
		{
			if (str[i] == '*' && str[i + 1] == '.')
				fl->min = va_arg(ap, int);
			else if (str[i] == '*' && str[i - 1] == '.')
				fl->max = va_arg(ap, int);
		}
		fl = ft_recup_min_max(str, fl);
	}
	else if (fl->star == 1)
		fl->count = va_arg(ap, int);
	return (fl);
}

t_flag			*ft_parse_utils(t_flag *fl)
{
	if (fl->mark == 1 && fl->min < 0)
	{
		fl->minus = 1;
		fl->min = -fl->min;
	}
	if (fl->mark == 1 && fl->max < 0 && fl->star == 0)
	{
		fl->minus = 1;
		fl->min = -fl->max;
		fl->max = 0;
	}
	else if (fl->count < 0)
	{
		fl->count = -fl->count;
		fl->minus = 1;
	}
	return (fl);
}

t_flag			*ft_parse_flag_core(char *str, t_flag *buffer, va_list ap)
{
	t_flag		*flag_buffer;

	flag_buffer = ft_parse_flag_buffer(buffer, str);
	flag_buffer = ft_parse_mark_minus(str, flag_buffer);
	flag_buffer = ft_parse_star(str, flag_buffer, ap);
	flag_buffer = ft_parse_utils(flag_buffer);
	return (flag_buffer);
}
