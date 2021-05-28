/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:04:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:28:39 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

size_t		ft_count(unsigned long long int nb, int base)
{
	int		i;

	i = 0;
	while (nb / base > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

int			ft_power(int nb, int power)
{
	if (power < 0)
		return (-1);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb * 1);
	return (ft_power(nb, 1) * ft_power(nb, power - 1));
}

int			ft_atoi(char *str)
{
	int		neg;
	int		ret;
	int		i;

	neg = 1;
	ret = 0;
	i = 0;
	while (str[i] > 9 && str[i] < 13)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = (ret * 10) + (str[i++] - 48);
	return (ret * neg);
}

void		ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
