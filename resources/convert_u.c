/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:23:04 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 09:26:40 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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

static char			*ft_new(size_t len)
{
	char			*ret;

	if (!len)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ret);
}

static char			*ft_itoa2(unsigned int nb)
{
	char			*ret;
	int				i;

	i = 0;
	ret = ft_new((i += ft_count_nb(nb)));
	ret[i--] = '\0';
	while (nb >= 10)
	{
		ret[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	ret[i] = (nb % 10) + 48;
	return (ret);
}

t_flag				*ft_convert_u(unsigned int nb, t_flag *fl)
{
	fl->ret_conv = (unsigned char *)ft_itoa2(nb);
	fl->count_conv = ft_strlen(fl->ret_conv);
	return (fl);
}
