/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:23:04 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 15:30:03 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static size_t		ft_count_nb(unsigned int nb)
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

static char		*ft_new(size_t len)
{
	char	*ret;

	if (!len)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ret);
}

static char		*ft_itoa2(unsigned int nb)
{
	int				neg;
	char			*ret;
	unsigned int	i;

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

t_flag		*ft_converat_u(unsigned int nb, const t_flag *flag_buffer)
{
	char		*buff;
	t_flag		*ret;

	ret = (t_flag *)flag_buffer;
	ret->ret_conv = ft_itoa2(nb);
	ret->count_conv = ft_strlen(buff);
	return (ret);
}








