/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:55:00 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/22 14:14:33 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_erreur(char *base)
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
			if (base[n] == base[i] || (base[n] == '-' || base[n] == '+')
					|| (base[i] == '-' || base[i] == '+'))
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
	ft_putchar(base[n % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	int				size;

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
