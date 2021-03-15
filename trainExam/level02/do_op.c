int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][1] == '+')
			printf("%d", atoi(argv[1][0]) + atoi(argv[3]));
	}
	return (0);
}
