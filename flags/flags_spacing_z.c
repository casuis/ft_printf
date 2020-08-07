/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spacing_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2020/08/07 03:57:46 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"


void		ft_flag_spacing(char *str, int count, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i++] - 48);
		while (count < nb)
		{
			ft_putchar(c);
			count++;
		}
	}
}

void		ft_flag_spacing_arg(va_list ap)
{
	int		i;
	int		buff;

	i = 0;
	buff = va_arg(ap, int);
	while (i <  buff)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_flag_position(va_list ap, char *str)
{
	int		i;
	int		buff;
	int		count;

	i = 0;
	while (((count = ft_parse_convert(&str[i], ap)) <0) && str[i] != ' ')
		i++;
	i = 0;
	str = &str[i + 1];
	ft_flag_spacing(str, count, ' ');
}

void		ft_fct_test(char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	ft_flag_position(ap, str);
	va_end(ap);
}

int			main(int argc, char **argv)
{
	ft_fct_test(argv[1], atoi(argv[2]), argv[3]);
	return (0);
}
