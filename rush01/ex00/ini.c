/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:44:19 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/21 10:44:56 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ini(int tab[6][6])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}