/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:04:10 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 19:19:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

size_t		ft_count(int nb, int base)
{
	int	i;

	i = 0;
	while(nb / base > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char		*ft_create(int len)
{
	char	*ret;
	int	i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len + 1)
		ret[i++] = '\0'; 
	return (ret);
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

char		*ft_lower_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char		*ft_upper_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

size_t		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	neg;
	int	ret;
	int	i;

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
