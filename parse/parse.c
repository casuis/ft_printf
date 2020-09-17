/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:46:19 by asimon            #+#    #+#             */
/*   Updated: 2020/09/17 18:19:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../resources/ft_utils.c"

//parse pour le flag '.' min et max
t_flag		*ft_parse_mark_minus(char *str, t_flag *flag_buffer)
{
	int			i;
	int			nb;
	t_flag		*ret;

	i = 0;
	ret = flag_buffer;
	if (ret -> mark == 1 && !(ret -> star > 0))
	{
		ret -> min_size = ft_atoi(&str[i]);
		while (str[i] != '.')
			i++;
		ret -> max_size = ft_atoi(&str[++i]);
		return (ret);
	}
	if (ret -> minus == 1 || ret -> zero == 1)
	{
		while (!(str[i] >= '0' && str[i] <= '9') && str[i])
			i++;
		ret -> count = ft_atoi(&str[i]);
		return (ret);
	}
	return (ret);
}

//Parse la sting pour les differents flags et les mettres dans le buffer
t_flag			*ft_parse_flag_buffer(t_flag *flag_buffer, char *str)
{
	int		i;
	t_flag			*ret;

	i = 0;
	ret = flag_buffer;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '.')
			ret -> mark = 1;
		if (str[i] == '-')
			ret -> minus = 1;
		if (str[i] == '0' && !(str[i - 1] >= '0' && str[i - 1] <= '9') 
				&& (str[i - 1] != '.') && flag_buffer -> minus != 1)
			ret -> zero = 1;
		if (str[i] == '*' && !(str[i - 1] >= '0' & str[i -1] <= '9'))
			ret -> star += 1; 
		i++;
	}
	if (ret -> minus == 1 && ret -> mark == 1)
		ret -> minus = 0;
	if (ret -> mark == 1)
		ret -> zero = 1;
	return (ret);
}

void			ft_parse_stars(char *str, t_flag *flag_buffer, va_list ap)
{
	int		i;

	i = 0;
	if (flag_buffer -> star == 2 && flag_buffer -> mark == 1)
	{
		flag_buffer -> min_size = va_arg(ap, int);
		flag_buffer -> max_size = va_arg(ap, int);
		flag_buffer -> star -= 2;
	}
	else if (flag_buffer -> star == 1 && flag_buffer -> mark == 1)
	{
		while (str[i] && str[i] != ' ')
		{
			if (str[i] == '*' && str[i + 1] == '.')
				flag_buffer -> min_size = va_arg(ap, int);
			else if (str[++i] == '*' && str[i - 1] == '.')
				flag_buffer -> max_size = va_arg(ap, int);
		}
		flag_buffer -> star -= 1;
	}
	else if (flag_buffer -> star == 1)
		flag_buffer -> count = va_arg(ap, int);
	printf("max_size: %d\nmax_size: %d\n", flag_buffer -> min_size, flag_buffer -> max_size);
}

void			ft_parse_core(char *str, t_struct *buffer, va_list ap)
{
	t_flag		*flag_buffer;

	flag_buffer = ft_parse_flag_buffer(buffer -> flag_info, str);
	if (flag_buffer -> star > 0)
		ft_parse_stars(str, flag_buffer, ap);
	flag_buffer = ft_parse_mark_minus(str, flag_buffer);
}

void		ft_test(char *str, ...)
{
	va_list		ap;
	t_flag		*flag_buffer;

	if (!(flag_buffer = (t_flag *)malloc(sizeof(t_flag) * 1)))
		return ;
	va_start(ap, str);
	ft_parse_flag_buffer(flag_buffer, str);
	ft_parse_stars(str, flag_buffer, ap);
	va_end(ap);
}

int			main(int argc, char *argv[])
{
	ft_test(argv[1], atoi(argv[2]), atoi(argv[3]));
	return 0;
}
