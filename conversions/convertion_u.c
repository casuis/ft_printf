/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:23:04 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 02:26:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int	ft_count_nb(unsigned int nb)
{
	unsigned int	ret;

	ret = 1;
	while (nb >= 10)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_new(size_t len)
{
	char	*ret;

	if (!len)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ret);
}

char			*ft_itoa2(unsigned int nb)
{
	unsigned int		i;
	int		neg;
	char	*ret;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		i += 1;
		neg = 1;
	}
	ret = ft_new((i += ft_count_nb(nb)));
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

void		ft_convertion_u(unsigned int nb)
{

	ft_putstr(ft_itoa2(nb));

}
