#include <unistd.h>

int main(void)
{
	char c = 'A';
	char b = 'a';
	while(c <= 'Z')
	{
		if (c % 2 == 0)
			write(1, &c, 1);
		else
			write(1, &b, 1);
		b++;
		c++;
	}
	return (0);
}
