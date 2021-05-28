/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pourc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:44:37 by asimon            #+#    #+#             */
/*   Updated: 2021/03/09 09:26:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_pourc(t_flag *fl)
{
	unsigned char		pour;

	pour = 37;
	if (!(fl->ret_conv = malloc(sizeof(unsigned char) * 2)))
		return (NULL);
	fl->ret_conv[0] = pour;
	fl->ret_conv[1] = '\0';
	fl->count_conv = 1;
	return (fl);
}
