/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:13:37 by asimon            #+#    #+#             */
/*   Updated: 2020/08/18 18:36:03 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

// compter tous les args
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
	int			count_arg;
	t_struct	*buff;
	va_list		ap;

	va_start(ap, str);
	count_arg = ft_count_arg(str);
	buff = ft_init(count_arg);
	ft_parse_flag_buffer(buff -> flag_info, str);
}
