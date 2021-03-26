/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:02:10 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/25 11:24:51 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_erreur2(char c, char *base);
int		ft_atoi(char *str, unsigned int size, char *base)
{
	int i;
	int nbr;
	int sign;
	int compt;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 0;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = 1 - sign;
	nbr = 0;
	while (str[i])
	{
		if (ft_erreur2(str[i], base) == 1)
			return (nbr);
		compt = 0;
		while (str[i] != base[compt])
			compt++;
		nbr = (nbr * size) + (str[i] - str[i]) + compt;
		i++;
	}
	if (sign)
		nbr *= -1;
	return (nbr);
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
			if ((base[n] == base[i] || (base[n] == '-' || base[n] == '+')
						|| (base[n] >= 9 && base[n] <= 13) || base[n] == ' ')
						|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
				return (1);
			i++;
		}
		n++;
		i = (n + 1);
	}
	return (0);
}

int		ft_erreur2(char c, char *base)
{
	int i;

	i = 0;	
	while(c != base[i])
	{
		if (base[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	long int			i;
	unsigned int		size;

	size = 0;
	if (ft_erreur(base) == 1)
			return (0);
	while (base[size] != '\0')
		size++;
	i = ft_atoi(str, size, base);
	return (i);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
