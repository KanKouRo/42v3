/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:26:54 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/09 16:07:26 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_num2(char a, char b, char c, char *d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, d, 1);
	if (a != '9' || b != '8')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
	*d = *d + 1;
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '7')
		{
			c = a;
			while (c <= '9')
			{
				d = (b + 1);
				while (d <= '9')
					ft_put_num2(a, b, c, &d);
				c++;
			}
			b++;
		}
		a++;
	}
	write(1, "98 99", 5);
}

int main(void)
{
	ft_print_comb2();
}
