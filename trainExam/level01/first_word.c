#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc <= 1)
	{
		(write, "\n", 1);
		return (0);
	}
	while(argv[1][i] != '\0')
	{
		while((argv[1][i] == ' ') || (argv[1][i] == '\t'))
			i++;
		while((argv[1][i] >= 33) && (argv[1][i] <= 126))
			write(1, &argv[1][i++], 1);
		return (0);
	}
}
