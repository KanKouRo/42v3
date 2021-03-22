/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antidouble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:51:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/03/21 10:52:57 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		antidouble(int tab[6][6], int lin, int col, int val)
{
	int i;

	if (col == 1 && lin == 1)
		return (1);
	i = 1;
	while (i < col)
	{
		if (tab[lin][i] == val)
			return (0);
		i++;
	}
	i = 1;
	while (i < lin)
	{
		if (tab[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}
