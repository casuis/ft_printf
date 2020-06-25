#include <stdio.h>
#include <unistd.h>
#include <string.h>

void		ft_convertion_p(void *p)
{
	unsigned long adr;
	char const *base;
	char res[9];
	int i;

	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	putchar ('0');
	putchar ('x');
	while (i < 9)
	{
		putchar (res[i]);
		i++;
	}

