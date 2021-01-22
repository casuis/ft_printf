/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:56:04 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 20:57:00 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_flag_buffer(t_flag *flag_buffer, char *str)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '%')
	{
		if (str[i] == '.' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			F_MARK = 1;
		if (str[i] == '-')
			F_MINUS = 1;
		if (str[i] == '0' && !(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& (str[i - 1] != '.') && F_MINUS != 1)
			F_ZERO = 1;
		if (str[i] == '*' && !(str[i - 1] > '0' & str[i - 1] <= '9'))
			F_STAR += 1;
		i++;
	}
	if (F_MARK == 0 && F_ZERO == 0 && F_STAR == 0 && F_MINUS == 0)
		F_COUNT = ft_atoi(str);
	if (F_MINUS == 1)
		F_ZERO = 0;
	return (flag_buffer);
}

t_flag			*ft_parse_mark_minus(char *str, t_flag *flag_buffer)
{
	int			i;

	i = 0;
	if (F_MARK == 1 && F_STAR == 0)
	{
		if (str[i] == '0')
			while (!(str[i] >= '1' && str[i] <= '9') && str[i] != '.')
				i++;
		F_WIDTH_MIN = ft_atoi(&str[i]);
		if (F_WIDTH_MIN < 0)
			F_WIDTH_MIN = -F_WIDTH_MIN;
		while (str[i] != '.')
			i++;
		F_WIDTH_MAX = ft_atoi(&str[++i]);
		return (flag_buffer);
	}
	else if (!(F_MARK == 1))
	{
		while (!(str[i] >= '0' && str[i] <= '9') && (str[i] && str[i] != ' ')
		&& str[i] != '%')
			i++;
		F_COUNT = ft_atoi(&str[i]);
		return (flag_buffer);
	}
	return (flag_buffer);
}

t_flag			*ft_parse_star(char *str, t_flag *flag_buffer, va_list ap)
{
	int			i;

	i = -1;
	if (F_STAR == 2 && F_MARK == 1)
	{
		F_WIDTH_MIN = va_arg(ap, int);
		F_WIDTH_MAX = va_arg(ap, int);
	}
	else if (F_STAR == 1 && F_MARK == 1)
	{
		while (str[++i] && str[i] != ' ')
		{
			if (str[i] == '*' && str[i + 1] == '.')
				F_WIDTH_MIN = va_arg(ap, int);
			else if (str[i] == '*' && str[i - 1] == '.')
				F_WIDTH_MAX = va_arg(ap, int);
		}
		flag_buffer = ft_recup_min_max(str, flag_buffer);
	}
	else if (F_STAR == 1)
		F_COUNT = va_arg(ap, int);
	return (flag_buffer);
}

t_flag			*ft_parse_utils(t_flag *flag_buffer)
{
	if (F_MARK == 1 && F_WIDTH_MIN < 0)
	{
		F_MINUS = 1;
		F_WIDTH_MIN = -F_WIDTH_MIN;
	}
	if (F_MARK == 1 && F_WIDTH_MAX < 0 && F_STAR == 0)
	{
		F_MINUS = 1;
		F_WIDTH_MIN = -F_WIDTH_MAX;
		F_WIDTH_MAX = 0;
	}
	else if (F_COUNT < 0)
	{
		F_COUNT = -F_COUNT;
		F_MINUS = 1;
	}
	return (flag_buffer);
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
