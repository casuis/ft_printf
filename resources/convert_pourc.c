/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pourc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:44:37 by asimon            #+#    #+#             */
/*   Updated: 2021/01/07 14:05:31 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flag		*ft_convert_pourc(t_flag *flag_buffer)
{
	unsigned char		pour;

	pour = 37;
	if (!(F_RET_CONV = malloc(sizeof(unsigned char) * 2)))
		return (NULL);
	F_RET_CONV[0] = pour;
	F_RET_CONV[1] = '\0';
	F_CONV_COUNT = 1;
	return (flag_buffer);
}
