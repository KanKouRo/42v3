/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:30:59 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/24 12:51:15 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *tab;
	int n;

	tab = NULL;
	if (min >= max)
		return (tab);
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	i = 0;
	n = min;
	while (i < (max - min))
	{
		tab[i] = n;
		n++;
		i++;
	}
	return (tab);
}
