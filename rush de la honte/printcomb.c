/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:57:11 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/13 16:09:27 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_num_char(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_putchar(char a, char s, char v)
{
	if (a != '7')
	{
		write(1, &v, 1);
		write(1, &s, 1);
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;
	char s;

	a = '1';
	s = '2';
	while (a < '9')
	{
		b = (a + 1);
		while (b < '9')
		{
			c = (b + 1);
			while (c <= '9')
			{
				ft_num_char(a, b, c);
				ft_putchar(a, s, v);
				c++;
			}
			b++;
		}
		a++;
	}
}
