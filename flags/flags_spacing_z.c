/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spacing_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:45 by asimon            #+#    #+#             */
/*   Updated: 2020/08/06 15:58:14 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"


static void		ft_flag_spacing(char *str, int count, char c)
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

static void		ft_flag_spacing_arg(va_list ap)
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

void		ft_check_flag(char *str, va_list ap)
{
	int		i;
	int		count;
	int		nb;
	
	i = 0;
	nb = va_arg(ap, int);
	count = ft_count(nb, 10) + 1;
	if (str[i] == '0')
		ft_flag_spacing(&(str[i + 1]), count, '0');
	if (str[i] > '0')
		ft_flag_spacing(&(str[i]), count, ' ');
	if (str[i] == '*')
		ft_flag_spacing_arg(ap);
}
