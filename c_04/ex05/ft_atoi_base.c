/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:02:10 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/20 17:33:48 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
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

void	ft_putnbr(unsigned int n, char *base, unsigned int size)
{
	if (n > size - 1)
	{
		ft_putnbr(n / size, base, size);
		n %= size;
	}
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
		ft_putnbr(-nbr, base, size);
	}
	else
	{
		ft_putnbr(nbr, base, size);
	}
}

int		ft_atoi_base(char *str, char *base)
{
	long int i;

	i = ft_atoi(str);
	ft_putnbr_base(i, base);
	return (i);
}
