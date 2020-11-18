/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:00 by asimon            #+#    #+#             */
/*   Updated: 2020/11/18 02:52:06 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_flag			*ft_sconv(char *str, va_list ap)
{
	int			i;
	t_flag		*flag_buffer;

	i = -1;
	flag_buffer = ft_create_flag_buffer();
	while (str[++i] != ' ' && str[i])
		if (ft_send_conv(str[i]) != 0 && ft_send_conv(str[i]) != -1)
			flag_buffer->conv = ft_send_conv(str[i]);
	if (flag_buffer->conv != ' ')
		return (ft_parse_flag_core(str, flag_buffer, ap));
	return (flag_buffer);
}

static size_t			ft_count_add(t_flag *flag_buffer, size_t count)
{
	if (flag_buffer->ret_count > 0)
		count += flag_buffer->ret_count;
	free(flag_buffer);
	return (count);
}

size_t					ft_read_casu(char *str, va_list ap)
{
	int			i;
	size_t		count;
	t_flag		*flag_buffer;

	i = 0;
	count = 0;
	str = ft_protect_str(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag_buffer = ft_sconv(&str[i + 1], ap);
			if (flag_buffer->conv != ' ')
			{
				flag_buffer = ft_parse_conv(flag_buffer, ap);
				str = ft_flag_position(&str[++i], flag_buffer, ap);
				i = 0;
			}
			count = ft_count_add(flag_buffer, count);
		}
		else if (str[i] != '%' && str[i] != '\0')
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

size_t			ft_printf(char *str, ...)
{
	va_list		ap;
	size_t		ret;

	ret = 0;
	va_start(ap, str);
	ret = ft_read_casu(str, ap);
	va_end(ap);
	return (ret);
}

int main(int argc, const char *argv[])
{
	ft_printf((char *)argv[1], atoi(argv[2]));
	printf("\n");
	printf(argv[1], atoi(argv[2]));
	return 0;
}
