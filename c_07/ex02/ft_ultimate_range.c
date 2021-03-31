/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:51:18 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/24 17:27:33 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int ems;

	i = 0;
	*range = NULL;
	if (min >= max)
		return (0);
	if (!(*range = malloc(sizeof(int) * (max - min))))
		return (-1);
	ems = (max - min);
	while (i < ems)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
