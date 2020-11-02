/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:13:37 by asimon            #+#    #+#             */
/*   Updated: 2020/11/02 17:54:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_core(char *str, ...)
{
	va_list		ap;
	t_flag		*flag_buffer;

	va_start(ap, str);
	flag_buffer = ft_create_flag_buffer(flag_buffer);
	ft_read_casu(str, flag_buffer, ap);
	va_end(ap);
	free(flag_buffer);
}

int			main(int argc, char **argv)
{
	ft_core(argv[1], atoi(argv[2]), atoi(argv[3]), -044);
	ft_putstr("\n");
	printf(argv[1], atoi(argv[2]), atoi(argv[3]), -044);
	getchar();
	return (0);
}
