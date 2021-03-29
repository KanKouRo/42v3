#include <stdlib.h>

int ft_size(long nbr)
{
    int size;

    size = 0;
    if (nbr < 0)
    {
        nbr *= -1;
        size++;
    }
    while (nbr > 0)
    {
        nbr /= 10;
        size++;
    }
    return (size);
}

char *ft_itoa(int nbr)
{
    char *str;
    long n;
    int i;

    n = nbr;
    i = ft_size(n);
    if (!(str = malloc(sizeof(char) * i + 1)))
    {
        return (NULL);
    }
    str[--i] = '\0';
    if (n == 0)
    {
        str[0] = '0';
        return (str);
    }
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    while (n > 0)
    {
        str[i] = (n % 10) + '0';
        n /= 10;
        i--;
    }
    return (str);
}

#include <stdio.h>
int main(void)
{
    printf("%s", ft_itoa(-2147483648));
    return (0);
}