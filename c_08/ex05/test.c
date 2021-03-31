#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	while (src[j] != '\0')
		j++;
	str = malloc(sizeof(str) * (j + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t;
	int			i;

	if (ac < 0)
		ac = 0;
	if (!(t = malloc((ac + 1) * sizeof(t_stock_str))))
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		t[i].size = ft_strlen(av[i]);
		t[i].str = av[i];
		t[i].copy = ft_strdup(av[i]);
	}
	t[i].str = 0;
	return (t);
}

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
    int i;

    i = 0;
    while (par[i])
    {
        ft_putstr(par[i].str);
        ft_putnbr(par[i].size);
        ft_putstr(par[i].copy);
        i++;
    }
    
}