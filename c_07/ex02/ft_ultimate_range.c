/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:34:53 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/22 11:25:37 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	max -= min;
	if (!(*range = malloc(sizeof(int) * (max - min))))
		return (-1);
	while (i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max);
}
