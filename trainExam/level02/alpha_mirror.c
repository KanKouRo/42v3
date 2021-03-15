/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:33:37 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/25 15:04:05 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int main(int argc, char ** argv)
{
	int i;
	char ltr;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			ltr = 'z' - argv[1][i] + 'a';
			write(1, &ltr, 1);
			i++;
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			ltr = 'Z' - argv[1][i] + 'A';
			write(1, &ltr, 1);
			i++;
		}
		else
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
