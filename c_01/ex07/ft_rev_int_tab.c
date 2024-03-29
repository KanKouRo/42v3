/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:22:52 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/10 14:42:37 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int swap;

	i = 0;
	j = (size - 1);
	while (i <= j)
	{
		swap = tab[i];
		tab[i] = tab[j];
		tab[j] = swap;
		j--;
		i++;
	}
}
