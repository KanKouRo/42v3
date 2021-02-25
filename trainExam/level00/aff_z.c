
#include <unistd.h>
char aff_a(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'z')
		{
			write(1, &str[i], 1);
			return(str[i]);
		}
		else
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "z", 1);
		write(1, "\n", 1);
		return (0);
	}
	if (argc == 2)
		aff_a(argv[1]);
	write(1, "\n", 1);
	return (0);
}
