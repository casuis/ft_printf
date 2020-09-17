#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

t_struct		*create_buff()
{
	t_struct	*buff;

	if (!(buff = malloc(sizeof(t_struct) * 5)))
		return (NULL);
	return (buff);
}

t_flag			*create_flag(t_struct *buff)
{
	t_flag		*ret;

	if (!(buff -> flag_info = malloc(sizeof(t_flag) * 1)))
		return (NULL);
	ret = buff -> flag_info;
	return (ret);
}

t_struct		*test(t_struct *buff, ...)
{
	va_list		ap;
	t_flag		*flag_buff;
	int			i;
	int			test;


	i = 0;
	test = 1;
	va_start(ap, buff);
	buff = create_buff();
	while (i < 5)
	{
		flag_buff = create_flag(buff + i);
		flag_buff -> star = test;
		i++;
		test++;
	}
	va_end(ap);
	return (buff);
}

int		main(int argc, char **argv)
{
	int		i;
	t_struct	*buffer;
	t_flag		*flag_buffer;

	i = 0;
	buffer = test(buffer, argv[1], argv[2], argv[3], argv[4], argv[5]);
	while (i < 5)
	{
		printf("%d\n", (buffer + i) -> flag_info -> star);
		i++;
	}
	return (0);
}
