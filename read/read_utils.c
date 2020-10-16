/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2020/10/16 07:33:16 by asimon           ###   ########.fr       */
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

t_flag		*ft_srch_conv(t_flag *buff, char *str, va_list ap)
{
	t_flag		*flag_buffer;
	int			i;

	i = -1;
	flag_buffer = (t_flag *)buff;
	flag_buffer = ft_parse_flag_core(str, flag_buffer, ap);
	while (str[++i] != ' ' && str[i])
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			flag_buffer->conv = ft_send_conv(str[i]);
	return (flag_buffer);
}

static char		*ft_protect_str(const char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)str;
	while (ret[i])
		i++;
	ret[i] = '\0';
	return (ret);
}

void		ft_read_casu(char *str, t_flag *flag_buffer, va_list ap)
{
	int		i;

	i = 0;
	str = ft_protect_str(str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		else if (str[i] == '%')
		{
			flag_buffer = ft_srch_conv(flag_buffer, &str[i + 1], ap);
			if (flag_buffer->conv != ' ')
			{
				flag_buffer = ft_parse_conv(flag_buffer, ap);
				str = ft_flag_position(&str[i], flag_buffer, ap);
			}
		}
		else if (str[i] != '%' && str[i] != '\0')
			ft_putchar(str[i]);
		i++;
	}
}

void		fct_test(char *str, ...)
{
	va_list		ap;
	t_flag		*flag_buffer;

	va_start(ap, str);
	flag_buffer = ft_create_flag_buffer(flag_buffer);
	ft_read_casu(str, flag_buffer, ap);
	va_end(ap);
	free(flag_buffer);
}

int			main(int argc, char **argv)
{
	fct_test(argv[1], atoi(argv[2]), atoi(argv[3]), 044);
	ft_putstr("\n");
	printf(argv[1], atoi(argv[2]), atoi(argv[3]), 044);
	return (0);
}
