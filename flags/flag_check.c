/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:18:15 by asimon            #+#    #+#             */
/*   Updated: 2020/08/06 16:39:32 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_check_flag(char *str, va_list ap)
{
	int		i;
	int		count;
	int		nb;
	
	i = 0;
	nb = va_arg(ap, int);
	count = ft_count(nb, 10) + 1;
	if (str[i] == '-')
		ft_flag_position(ap, str);
	if (str[i] == '0')
		ft_flag_spacing(&(str[i + 1]), count, '0');
	if (str[i] > '0')
		ft_flag_spacing(&(str[i]), count, ' ');
	if (str[i] == '*')
		ft_flag_spacing_arg(ap);
}
