#include <unistd.h>
int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 3)
	{
		while (argv[1][j])
		{
			i = 0;
			while (argv[1][i] != argv[1][j])
				i++;
			if(i == j)
			{
				i = 0;
				while ((argv[2][i] && argv[2][i] != argv[1][j]))
						i++;
				if (argv[2][i] == argv[1][j])
					write(1, &argv[1][j], 1);
			}
			j++;
		}
	}
	write(1, "\n" ,1);
	return(0);
}

