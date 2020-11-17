/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:59:11 by asimon            #+#    #+#             */
/*   Updated: 2020/11/17 01:16:48 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_parse_flag_buffer(t_flag *flag_buffer, char *str)
{
	int				i;
	t_flag			*ret;

	i = 0;
	ret = flag_buffer;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '.' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			ret->mark = 1;
		if (str[i] == '-')
			ret->minus = 1;
		if (str[i] == '0' && !(str[i - 1] >= '0' && str[i - 1] <= '9')
				&& (str[i - 1] != '.') && flag_buffer->minus != 1)
			ret->zero = 1;
		if (str[i] == '*' && !(str[i - 1] >= '0' & str[i - 1] <= '9'))
			ret->star += 1;
		i++;
	}
	return (ret);
}

t_flag			*ft_parse_mark_minus(char *str, t_flag *flag_buffer)
{
	int			i;
	t_flag		*ret;

	i = 0;
	ret = flag_buffer;
	if (ret->mark == 1 && !(ret->star > 0))
	{
		ret->min_size = ft_atoi(&str[i]);
		if (ret->min_size < 0)
			ret->min_size = -ret->min_size;
		while (str[i] != '.')
			i++;
		ret->max_size = ft_atoi(&str[++i]);
		return (ret);
	}
	else if (!(flag_buffer->mark == 1))
	{
		while (!(str[i] >= '0' && str[i] <= '9') && (str[i] && str[i] != ' '))
			i++;
		ret->count = ft_atoi(&str[i]);
		return (ret);
	}
	return (ret);
}

t_flag			*ft_parse_star(char *str, t_flag *flag_buffer, va_list ap)
{
	int			i;

	i = -1;
	if (flag_buffer->star == 2 && flag_buffer->mark == 1)
	{
		flag_buffer->min_size = va_arg(ap, int);
		flag_buffer->max_size = va_arg(ap, int);
	}
	else if (flag_buffer->star == 1 && flag_buffer->mark == 1)
	{
		while (str[++i] && str[i] != ' ')
			if (str[i] == '*' && str[i + 1] == '.')
				flag_buffer->min_size = va_arg(ap, int);
			else if (str[i] == '*' && str[i - 1] == '.')
				flag_buffer->max_size = va_arg(ap, int);
		flag_buffer = ft_recup_min_max(str, flag_buffer);
	}
	else if (flag_buffer->star == 1)
		flag_buffer->count = va_arg(ap, int);
	return (flag_buffer);
}

t_flag			*ft_parse_utils(t_flag *flag_buffer)
{
	if (flag_buffer->mark == 1 && flag_buffer->min_size < 0)
	{
		flag_buffer->minus = 1;
		flag_buffer->min_size = -flag_buffer->min_size;
	}
	if (flag_buffer->mark == 1 &&
	flag_buffer->max_size < 0 && flag_buffer->star < 2)
	{
		flag_buffer->minus = 1;
		flag_buffer->min_size = -flag_buffer->max_size;
		flag_buffer->max_size = 0;
	}
	else if (flag_buffer->count < 0)
	{
		flag_buffer->count = -flag_buffer->count;
		flag_buffer->minus = 1;
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
