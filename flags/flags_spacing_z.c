/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spacing_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2020/09/15 18:11:55 by asimon           ###   ########.fr       */
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
	while (((count = ft_parse_convert(&str[i], ap)) < 0) && str[i] != ' ')
		i++;
	i = 0;
	str = &str[i + 1];
	ft_flag_spacing(str, count, ' ');
}

void		ft_flag_mark(t_flag *flag_buffer)
{
	int		min;
	int		max;

	min = flag_buffer -> min_size;
	max = flag_buffer -> max_size;
	if (min > max)
		
}
