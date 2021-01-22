#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	unsigned char	c;

	c = '\x00';
	write(1, &c, 1);
	return 0;
}
