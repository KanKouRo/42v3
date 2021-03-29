#include <unistd.h>
#include "ft_stock_str.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= (-1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else 
		ft_putchar(n + '0');
}

void ft_show_tab(struct s_stock_str *par)
{
    while (par->str)
    {
        ft_putstr(par->str);
        ft_putnbr(par->size);
        ft_putstr(par->copy);
        par++;
    }
}

int main(ft_show_tab)