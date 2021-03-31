int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int mul = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' || argv[1][i] == 'z')
            {
                mul = (argv[1][i] - 97);
                while (mul >= 0)
                {
                    write(1, &argv[1][i], 1);
                    mul--;
                }
            if (argv[1][i] >= 'A' || argv[1][i] == 'Z')
            {
                mul = (argv[1][i] - 65);
                while (mul >= 0)
                {
                    write(1, &argv[1][i], 1);
                    mul--;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}