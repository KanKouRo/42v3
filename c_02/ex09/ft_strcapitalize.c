/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:31:23 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/12 16:45:47 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') \
			|| (str[i] >= 'A' && str[i] <= 'Z') \
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (j == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (j == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			i++;
			j = 0;
		}
		else
		{
			j = 1;
			i++;
		}
	}
	return (str);
}
