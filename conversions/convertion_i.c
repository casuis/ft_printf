/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 10:32:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/utils.c"
#include "../resources/ft_itoa.c"

static char		*ft_parse(char *str)
{
	if (str[0] == '0' && str[1] != 'x')
		return ("01234567");
	else if (str[0] == '0'  && str[1] == 'x')
		return ("0123456789abcdef");	
	else
		return ("0123456789");
}

void			ft_convertion_i(char *str)
{
	char	*base;
	int	nb;
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	base = ft_parse(str);
	if (*str == '0' )
		str++;
	if (*str == 'x')
		str++;
	nb = ft_atoi(str);
	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		tmp += (ft_strlen(base) * i) * (*str - 48);
		i--;
		str++;
	}
	tmp += *str - 48;
	ft_putstr(ft_itoa(tmp));

}

int		main(int argc, char **argv)
{
	ft_putstr("mon printf = ");
	ft_convertion_i(argv[1]);
	ft_putchar('\n');
	printf("vrai printf = %i\n", 0xA);
	return (0);
}
