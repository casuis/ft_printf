/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:53:26 by user42            #+#    #+#             */
/*   Updated: 2020/06/14 20:56:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t		ft_count_nb(int nb)
{
	int	ret;

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

char			*ft_itoa(int nb)
{
	int		i;
	int		neg;
	char	*ret;

	i = 0;
	neg = 0;
	if (nb == -2147483648)
		return ("-2147483648");
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
