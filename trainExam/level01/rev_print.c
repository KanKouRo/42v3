#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	int size = 0;
	int n = 1;
	while (argv[n][size] != '\0')
		argv[n][size++];
	size -= 1;
	while (size >= 0)
	{
		write(1, &argv[n][size], 1);
		size--;
	}
	argv[n][size] = '\0';
	write(1, "\n", 1);
	return (0);
}
