/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:13:37 by asimon            #+#    #+#             */
/*   Updated: 2020/08/06 16:13:08 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

static int		ft_count_arg(char *str)
{
	int		str_i;
	int		buff_i;
	int		ret;
	char	*buff;

	buff_i = 0;
	ret = 0;
	str_i = 0;
	buff = ft_create_table();
	while (str[str_i])
	{
		if (str[str_i++] == '%')
		{
			while (buff[buff_i] && (buff[buff_i] != str[str_i]))
				buff_i++;
			if (str[str_i] == buff[buff_i])
				ret++;
			str_i++;
			buff_i = 0;
		}
	}
	free(buff);
	return (ret);
}

int		ft_core(char *str, ...)
{
	unsigned int	i;
	unsigned int	y;
	va_list		ap;
	void		*tmp;

	i = 0;
	va_start(ap, str);
	y = ft_count_arg(str);
	while (str[i])
	{
		if (str[i] == '%' && y > 0)
		{
			ft_parse_convert((str + (++i)), ap);
			y--;
			if (str[i + 1] != '\0')
				i++;
		}
		else if (str[i] != '\0')
			ft_putchar(str[i++]);
	}
	return (1);
}
