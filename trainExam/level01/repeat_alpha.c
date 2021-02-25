#include <unistd.h>
int main(int argc, char **argv)
{
	int i = 0;
	int n = 1;
	int mul;

	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (n < argc)
	{
		i = 0;
		while (argv[n][i] != '\0')
		{
			if (argv[n][i] >= 'A' && argv[n][i] <= 'Z')
			{
				mul = (argv[n][i] - 65);
				while (mul >= 0)
				{
					write(1, &argv[n][i], 1);
					mul--;
				}
				i++;
			}
			else if (argv[n][i] >= 'a' && argv[n][i] <= 'z')
			{
				mul = (argv[n][i] - 97);
				while (mul >= 0)
				{
					write(1, &argv[n][i], 1);
					mul--;
				}
				i++;
			}
			else
			{
				write(1, &argv[n][i], 1);
				i++;
			}
		}
		n++;
	}
	write(1, "\n", 1);
}
	
