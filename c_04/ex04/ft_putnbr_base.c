/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:24:41 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/17 09:58:16 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (base[n] == base[i])
				return (1);
			else if (base[n] == '-' || base[n] == '+')
				return (1);
			else
				i++;
		}
		n++;
		i = (n + 1);
	}
	return (0);
}
int	ft_putnbr_base(int nbr, char *base)
{
	int i = 0;
	char  str[i];
	int convert[i];
	
	if (ft_erreur(base) == 0)
		return (0);
	str[i] = *base;
	convert[i] = nbr;
	while (str[i] > 0)
	{
		convert[i] = (str[i] % *base);
		str[i] = (str[i] / *base);
		i++;
	}
	return (*convert);
}

#include <stdio.h>
int main ()
{
	//char base[] = "01";
	printf("%d", ft_putnbr_base(12, "0123456789ABCDEF"));
	return (0);
}
