/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:27:27 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/11 13:57:51 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	size = 0;
	while (str[size] != '\0')
		size++;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	if (size == 0 || j == size)
		return (1);
	else
		return (0);
}
