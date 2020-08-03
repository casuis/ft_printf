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

static char		*ft_create_table()
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * 9)))
		return (NULL);
	ret[0] = 'c';
	ret[1] = 'x';
	ret[2] = 'X';
	ret[3] = 'u';
	ret[4] = 'p';
	ret[5] = 'd';
	ret[6] = 'i';
	ret[7] = 's';
	ret[8] = '\0';
	return (ret);
}

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
	return (ret);
}

static void		ft_parse_convert(char *c, va_list ap)
{
	if (*c == 'c')
		ft_convert_c(va_arg(ap, int));
	if (*c == 'x')
		ft_convert_x(va_arg(ap, int));
	if (*c == 'X')
		ft_convert_xx(va_arg(ap, int));
	if (*c == 'u')
		ft_convert_u(va_arg(ap, unsigned int));
	/*if (c == 'p')
		ft_convert_p(va_arg(ap, void));*/
	if (*c == 'd')
		ft_convert_d(va_arg(ap, int));
	if (*c == 'i')
		ft_convert_i(va_arg(ap, char*));
	if (*c == 's')
		ft_convert_s(va_arg(ap, char*));
	if (*c == '0')
		ft_flag(c + 1);
}

int		ft_printf(char *str, ...)
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
		if (str[i] == '%')
		{
			ft_parse_convert((str + (++i)), ap);
			if (str[i + 1] != '\0')
				i++;
		}
		else if (str[i] != '\0')
			ft_putchar(str[i]);
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	ft_printf("salut %d", atoi(argv[1]));
	return (0);
}
