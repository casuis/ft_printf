/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:53:26 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:28:12 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static size_t		ft_count_nb(int nb)
{
	int		ret;

	ret = 1;
	while (nb >= 10)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

static char			*ft_int_min(void)
{
	unsigned char	*str;

	str = (unsigned char *)ft_create(12);
	str = ft_strcpy((unsigned char *)"-2147483648", str);
	return ((char *)str);
}

char				*ft_itoa(int nb)
{
	int		i;
	int		neg;
	char	*ret;

	i = 0;
	neg = 0;
	if (nb == -2147483648)
		return (ft_int_min());
	if (nb < 0)
	{
		nb = -nb;
		i += 1;
		neg = 1;
	}
	ret = ft_create((i += ft_count_nb(nb)));
	ret[i--] = '\0';
	while (nb >= 10)
	{
		ret[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	ret[i] = (nb % 10) + 48;
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}
