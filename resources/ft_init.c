/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:27:50 by asimon            #+#    #+#             */
/*   Updated: 2020/09/15 16:49:49 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_struct		*ft_create_buffer(int count)
{
	t_struct		*buff;

	if (!(buff = malloc(sizeof(t_struct) * count)))
		return (NULL);
	return (buff);
}

t_flag			*ft_create_flag_buffer(t_flag *flag_buffer)
{
	t_flag		*ret;

	ret = flag_buffer;
	if (!(ret = malloc(sizeof(t_flag) * 1)))
		return (NULL);
	ret -> minus = 0;
	ret -> mark = 0;
	ret -> star = 0;
	ret -> zero = 0;
	ret -> min_size = 0;
	ret -> max_size = 0;
	ret -> conv = ' ';
	ret -> count = 0;
	return (ret);
}

t_struct		*ft_init(int count_arg)
{
	t_struct	*buff;
	t_flag		*flag_buffer;

	buff = ft_create_buffer(count_arg);
	flag_buffer = buff -> flag_info;
	flag_buffer = ft_create_flag_buffer(flag_buffer);
	return (buff);
}
