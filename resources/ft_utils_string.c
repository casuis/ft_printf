/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:43:00 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:29:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char		*ft_create(int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len + 1)
		ret[i++] = '\0';
	return (ret);
}

char		*ft_protect_str(char *str)
{
	int			i;
	char		*ret;

	i = 0;
	ret = (char *)str;
	while (ret[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = '\0';
	while (i >= 0)
	{
		ret[i] = str[i];
		i--;
	}
	return (ret);
}

char		*ft_lower_case(char *str)
{
	int		i;

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
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

size_t		ft_strlen(unsigned char *str)
{
	int		i;

	i = 0;
	if (str != NULL)
		while (str[i])
			i++;
	return (i);
}
