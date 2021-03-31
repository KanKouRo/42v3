/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:33:03 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/31 10:46:51 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str);
int				i_base(char c, char *base);
int				is_base(char c, char *base);
int				check_base(char *base);
void			ft_rev_tab(char *tab, int size);

long int		ft_atoi_base(char *str, char *base)
{
	long int	atoi;
	int			negative;

	atoi = 0;
	negative = 1;
	if (!check_base(base))
		return (0);
	while (*str == '\t' || *str == '\v' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (is_base(*str, base))
	{
		atoi = atoi * ft_strlen(base) + i_base(*str, base);
		str++;
	}
	return (atoi * negative);
}

long int		ft_fill_tab(char *tab, long int num, char *base_to)
{
	int			negative;
	int			base_len;
	long int	i;

	base_len = ft_strlen(base_to);
	negative = 0;
	i = 0;
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}
	if (num == 0)
	{
		tab[i++] = base_to[num % base_len];
	}
	while (num)
	{
		tab[i++] = base_to[num % base_len];
		num = num / base_len;
	}
	if (negative)
		tab[i++] = '-';
	return (i);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	num;
	int			i;
	char		*tab;

	i = 0;
	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	if (!(tab = malloc(sizeof(char) * 34)))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	i = ft_fill_tab(tab, num, base_to);
	ft_rev_tab(tab, i);
	tab[i] = '\0';
	return (tab);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	printf("%s", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}

