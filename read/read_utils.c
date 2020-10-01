/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2020/09/28 10:10:35 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		ft_send_conv(char c)
{
	if (c == 'c')
		return (c);
	else if (c == 'x')
		return (c);
	else if (c == 'X')
		return (c);
	else if (c == 'u')
		return (c);
	else if (c == 'p')
		return (c);
	else if (c == 'd')
		return (c);
	else if (c == 'i')
		return (c);
	else if (c == 's')
		return (c);
	else if (!(c <= '9' && c >= '0') && (c != '*') && (c != '.') && (c != '-'))
		return (0);
	return (-1);
}

int			ft_core_conv(t_struct *buff, char *str, va_list ap)
{
	t_flag		*flag_buffer;
	int			i;

	i = -1;
	flag_buffer = buff->flag_info;
	flag_buffer = ft_parse_core(str, buff, ap);
	while (str[++i] != ' ' && str[i])
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			flag_buffer->conv = ft_send_conv(str[i]);
	if (flag_buffer->conv != 0)
		return (1);
	return (0);
}

void		ft_read_casu(char *str, t_struct *buff, va_list ap)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		else if (ft_core_conv(buff, &str[i + 1], ap) == 1 && str[i] == '%')
			ft_parse_str_core(&str[i], buff, ap);
		else
			ft_putchar(str[i]);
	}
}

void			ft_test(char *str, ...)
{
	va_list		ap;
	t_struct		*buff;
	t_flag			*flag_buffer;
	int				ret;

	if (!(buff = malloc(sizeof(t_struct) * 1)))
		return ;
	if (!(buff -> flag_info = malloc(sizeof(t_flag) * 1)))
		return ;
	va_start(ap, str);
	ret = ft_core_conv(buff, str, ap);
	flag_buffer = buff -> flag_info;
	printf("conv : %c\ncount: %d\nmin_size: %d\nmax_size: %d\nzero: %d\nret: %d\n", flag_buffer -> conv, flag_buffer -> count, flag_buffer -> min_size, flag_buffer -> max_size, flag_buffer -> zero, ret);
	va_end(ap);
	free(buff);
	free(flag_buffer);
}
int			main(int argc, char **argv)
{
	ft_test(argv[1], atoi(argv[2]), atoi(argv[3]));
	return (0);
}
