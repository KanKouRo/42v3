/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:14:38 by cboutier          #+#    #+#             */
/*   Updated: 2021/03/21 15:40:07 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inic(int tab[6][6], char *str);
int		bonparametre(int arc, char *arv);
void	ini(int tab[6][6]);
int		solv(int tab[6][6], int lin, int col);

int		main(int argc, char **argv)
{
	int tab[6][6];

	if (bonparametre(argc, argv[1]))
	{
		ini(tab);
		inic(tab, argv[1]);
		solv(tab, 1, 1);
		if (tab[0][0] == 0)
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
