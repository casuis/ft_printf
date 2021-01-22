/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2021/01/22 18:54:00 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag			*ft_sconv(char *str, va_list ap)
{
	int			i;
	t_flag		*flag_buffer;

	i = -1;
	flag_buffer = ft_create_flag_buffer();
	while (str[++i] != ' ' && str[i] && F_CONV == ' ')
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			F_CONV = ft_send_conv(str[i]);
	if (F_CONV != ' ')
		return (ft_parse_flag_core(str, flag_buffer, ap));
	return (flag_buffer);
}

static size_t			ft_count_add(t_flag *flag_buffer, size_t count)
{
	if (F_RET_COUNT > 0)
		count += F_RET_COUNT;
	if (F_CONV == 'p' && F_MARK != 1)
	{
		free(F_PRE);
		free(F_RET_CONV);
	}
	free(flag_buffer);
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
	t_flag		*flag_buffer;
	char		*tmp;

	i = -1;
	count = 0;
	str = ft_protect_str(str);
	tmp = str;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			flag_buffer = ft_sconv(&str[i + 1], ap);
			if (F_CONV != ' ')
			{
				str = ft_flag_position(&str[++i], flag_buffer, ap);
				i = 0;
			}
			count = ft_count_add(flag_buffer, count);
		}
		else if (str[i] != '%' && str[i] != '\0')
			count += ft_putchar(str[i]);
	}
	return (ft_end(count, tmp));
}

int			ft_printf(char *str, ...)
{
	va_list		ap;
	size_t		ret;

	ret = 0;
	va_start(ap, str);
	ret = ft_core(str, ap);
	va_end(ap);
	return (ret);
}

int main(int argc, const char *argv[])
{
	static char *s_hidden = "hi low\0don't print me lol";

	ft_printf((char *)argv[1], atoi((char *)argv[2]), (char *)argv[3]);
	ft_printf("\n");
	//printf((char *)argv[1], s_hidden);
	return 0;
}
