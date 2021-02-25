/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:51:07 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/23 10:39:48 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_in_base(char c, char *base);
int		ft_baselen(char *base);
int		ft_atoi_base(char *str, char *base);

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
	unsigned int i;
	unsigned int size;

	size = 0;
	i = 0;
	while (base[size] != '\0')
		size++;
	if (ft_erreur(base) == 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base(2, base);
		ft_putnbr_base(147483648, base);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(nbr * (-1), base);
	}
	if (nbr > 0)
	{
		ft_putnbr_base(nbr / size, base);
		ft_putchar(base[nbr % size]);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 0;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = 1 - sign;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + str[i++] - '0';
	if (sign)
		nbr *= -1;
	return (nbr);
}

char	*ft_convert_base(char *nbr, char* base_from, char *base_to)
{
	int n;
	int res;

	n = ft_atoi(char nbr);
	if (!(res = ft_putnbr_base(n, base_to)));
		return(NULL);
	return(res);
}
