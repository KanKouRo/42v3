/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:23:21 by cboutier          #+#    #+#             */
/*   Updated: 2021/03/21 14:14:10 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	gauche(int tab[6][6], int lin, int col)
{
	int i;
	int max;
	int c;

	c = 0;
	i = 1;
	if (col != 4)
		return (1);
	max = -1;
	while (i < 5)
	{
		if (tab[lin][i] > max)
		{
			c++;
			max = tab[lin][i];
		}
		i++;
	}
	if (c != tab[lin][0])
		return (0);
	return (1);
}

int	droite(int tab[6][6], int lin, int col)
{
	int i;
	int max;
	int c;

	c = 0;
	i = 4;
	if (col != 4)
		return (1);
	max = -1;
	while (i > 0)
	{
		if (tab[lin][i] > max)
		{
			c++;
			max = tab[lin][i];
		}
		i--;
	}
	if (c != tab[lin][5])
		return (0);
	return (1);
}

int	haut(int tab[6][6], int lin, int col)
{
	int i;
	int max;
	int c;

	c = 0;
	i = 1;
	if (lin != 4)
		return (1);
	max = -1;
	while (i < 5)
	{
		if (tab[i][col] > max)
		{
			c++;
			max = tab[i][col];
		}
		i++;
	}
	if (c != tab[0][col])
		return (0);
	return (1);
}

int	bas(int tab[6][6], int lin, int col)
{
	int i;
	int max;
	int c;

	c = 0;
	i = 4;
	if (lin != 4)
		return (1);
	max = -1;
	while (i > 0)
	{
		if (tab[i][col] > max)
		{
			c++;
			max = tab[i][col];
		}
		i--;
	}
	if (c != tab[5][col])
		return (0);
	return (1);
}
