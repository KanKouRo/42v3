<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:35:25 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/31 10:35:51 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_rev_tab(char *tab, int size)
{
	int		i;
	int		swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[size - 1 - i];
		tab[size - i - 1] = tab[i];
		tab[i] = swap;
		i++;
	}
}

int		i_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		is_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_base(char *base)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] < 32
				|| base[i] > 127 || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
=======
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
>>>>>>> ceada882113b05f0db237d7e3f2c3c09b4059fa7
