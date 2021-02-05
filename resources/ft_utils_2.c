/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:15:34 by asimon            #+#    #+#             */
/*   Updated: 2021/01/26 19:58:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag			*ft_recup_min_max(char *str, t_flag *fl)
{
	int			i;

	i = 0;
	if (str[0] == '*' || (str[0] == '-' && str[1] == '*'))
	{
		while (str[i] && str[i] != ' ' && str[i] != '.')
			i++;
		fl->max = ft_atoi(&str[i + 1]);
	}
	else if (fl->min == '0')
		fl->min = ft_atoi(&str[i]);
	return (fl);
}
size_t			ft_flag_spacing(int count, char c)
{
	int			i;

	i = 0;
	if (count > 0)
	{
		while (i++ < count)
			ft_putchar(c);
		return (i - 1);
	}
	return (0);
}

unsigned char			*ft_strcpy(const unsigned char *src, unsigned char *dst)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strconcat(char *str, char *conc)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = str;
	tmp2 = conc;
	if (!(ret = malloc(sizeof(char) * (1 + ft_strlen((unsigned char *)str) +
	ft_strlen((unsigned char *)conc)))))
		return (NULL);
	while (*str)
	{
		ret[i++] = *str;
		str++;
	}
	while (*conc)
	{
		ret[i++] = *conc;
		conc++;
	}
	free(tmp);
	free(tmp2);
	return (ret);
}
