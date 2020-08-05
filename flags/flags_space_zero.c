#include "printf.h"


void		ft_flag_spacing(char *str, int count, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i++] - 48);
		while (count < nb)
		{
			ft_putchar(c);
			count++;
		}
	}
}

void		ft_check_flag(char *str, int nb)
{
	int		i;
	int		count;

	i = 0;
	count = ft_count(nb, 10) + 1;
	if (str[i] == '0')
		ft_flag_spacing(&(str[i + 1]), count, '0');
	if (str[i] > '0')
		ft_flag_spacing(&(str[i]), count, ' ');
}
