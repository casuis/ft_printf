/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:04:10 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 09:36:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	if(!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while(i < len + 1)
		ret[i++] = '\0'; 
	return (ret);
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
