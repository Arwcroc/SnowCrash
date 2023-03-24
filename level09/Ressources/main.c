#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	char c;
	while (av[1][i])
	{
		c = av[1][i];
		printf("%c", c - i);
		i++;
	}
}