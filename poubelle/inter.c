#include <unistd.h>

int main(int argc, char ** argv)
{
    int i;
    int j;
    int n;
    int p;
    char *str;

    if (argc == 3)
    {
        i = 0;
        j = 0;
        str[0] = 'p';
        while (argv[1][i] != '\0')
        {
            while (argv[2][j])
            {
                n = 0;
                if (argv[1][i] == argv[2][j])
                {
                    str[i] = argv[1][i];
                    while (str[n] != '\0')
                    {
                        if (str[n] == argv[1][i])
                        {
                            p = 1;
                        }
                        n++;
                    }
                    if (p = 0)
                    {
                        write(1, &argv[1][i], 1);
                        i++;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}