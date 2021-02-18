/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:24:41 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/18 16:34:21 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_erreur(char *base)
{
	int i;
	int n;

	i = 1;
	n = 0;
	if (base[n] == '\0' || base[n + 1] == '\0')
		return (1);
	while(base[n] != '\0')
	{
		while (base [i] != '\0')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (base[size] != '\0')
		size++;
	if (ft_erreur(base) == 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base(2,base);
		ft_putnbr_base(147483648,base);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(nbr * (-1),base);
	}
	if (nbr > 0)
	{
		ft_putnbr_base(nbr / size,base);
		ft_putchar(base[nbr%size]);
	}
}

int main ()
{
	ft_putnbr_base(256, "0123456789ABCDEF");
	return (0);
}
