#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int        ft_erreur(char *base)
{
    int i;
    int n;

    i = 1;
    n = 0;
    if (base[n] == '\0' || base[n + 1] == '\0')
        return (1);
    while (base[n] != '\0')
    {
        while (base[i] != '\0')
        {
            if (base[n] == base[i] || (base[n] == '-' || base[n] == '+'))
                return (1);
            i++;
        }
        n++;
        i = (n + 1);
    }
    return (0);
}

void	ft_putnbr(unsigned int n, char *base, unsigned int size)
{
	if (n > size - 1)
	{
		ft_putnbr(n / size, base, size);
		n %= size;
	}
	ft_putchar(base[n]);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int i;
    int size;

    size = 0;
    i = 0;
    while (base[size] != '\0')
        size++;
    if (ft_erreur(base) == 1)
        return ;
    if (nbr < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nbr, base, size);
    }
    else
    {
        ft_putnbr(nbr, base, size);
    }
}

#include <stdio.h>
int main ()
{
    ft_putnbr_base(0, "0123456789ABCDEF");
    return (0);
}
