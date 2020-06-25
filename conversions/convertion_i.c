/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:46:14 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 09:19:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/utils.c"

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
	char	*tmp;
	int	i;

	i = 0;
	base = ft_parse(str);
	if (*str == '0' )
		str++;
	if (*str == 'x')
		str++;
	nb = ft_atoi(str);
	i = ft_count(nb);
	tmp = ft_create(i);
	while (nb / ft_strlen(base) > 0)
	{
		tmp[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i--;
	}
	tmp[i] = (base[nb % ft_strlen(base)]);
	ft_putstr(tmp);
	free(tmp);
}

int		main(int argc, char **argv)
{
	ft_convertion_i(argv[1]);
	ft_putchar('\n');
	printf("%i\n", 033);
	return (0);
}
