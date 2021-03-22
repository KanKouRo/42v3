/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critaire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:53:20 by cboutier          #+#    #+#             */
/*   Updated: 2021/03/21 11:38:38 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	haut(int tab[6][6], int lin, int col);
int	bas(int tab[6][6], int lin, int col);
int	droite(int tab[6][6], int lin, int col);
int	gauche(int tab[6][6], int lin, int col);

int	critaire(int tab[6][6], int lin, int col, int val)
{
	val *= 1;
	if (gauche(tab, lin, col) && droite(tab, lin, col)
		&& haut(tab, lin, col) && bas(tab, lin, col))
		return (1);
	return (0);
}
