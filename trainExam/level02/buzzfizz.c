#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    int nb;
    nb = 0;

    if (nbr >= 0 && nbr <= 9)
        ft_putchar(nbr + '0');
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

void ft_buzzfizz(void)
{
    int nbr;

    nbr = 1;
    while (nbr <= 100)
    {
        if (nbr % 4 == 0)
        {
            if ((nbr % 4 == 0) && (nbr % 7 == 0))
                write(1, "buzzfizz", 8);
            else
                write(1, "buzz", 4);
        }
        else if (nbr % 7 == 0)
            write(1, "fizz", 4);
        else
            ft_putnbr(nbr);
        nbr++;
        ft_putchar('\n');
    }
}

int main(void)
{
    ft_buzzfizz();
    return (0);
}