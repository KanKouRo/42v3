#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int size = 0;
        while (argv[1][size] != '\0')
            size++;
        size -= 1;
        while (size >= 0)
        {
            write(1, &argv[1][size--], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}