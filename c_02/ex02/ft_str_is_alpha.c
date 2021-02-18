/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:46:30 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/12 16:35:46 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
		if ((str[i] >= 'a' && str[i] <= 'z') \
			|| (str[i] >= 'A' && str[i] <= 'Z'))
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
