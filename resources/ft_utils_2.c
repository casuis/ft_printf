/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:15:34 by asimon            #+#    #+#             */
/*   Updated: 2020/11/02 16:56:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char			*ft_create_table(void)
{
	char		*ret;

	if (!(ret = malloc(sizeof(char) * 9)))
		return (NULL);
	ret[0] = 'c';
	ret[1] = 'x';
	ret[2] = 'X';
	ret[3] = 'u';
	ret[4] = 'p';
	ret[5] = 'd';
	ret[6] = 'i';
	ret[7] = 's';
	ret[8] = '\0';
	return (ret);
}

t_flag			*ft_recup_min_max(char *str, t_flag *flag_buffer)
{
	int			i;
	t_flag		*ret;

	i = 0;
	ret = (t_flag*)flag_buffer;
	if (str[0] == '*')
	{
		while (str[i] && str[i] != ' ' && str[i] != '.')
			i++;
		ret->max_size = ft_atoi(&str[i + 1]);
	}
	else
		ret->min_size = ft_atoi(&str[i]);
	return (ret);
}

void			ft_flag_spacing(int count, char c)
{
	int			i;

	i = 0;
	if (count > 0)
		while (i++ < count)
			ft_putchar(c);
}
