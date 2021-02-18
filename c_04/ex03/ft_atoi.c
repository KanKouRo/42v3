/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:12:48 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/17 09:15:13 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;
	
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 0;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = 1 - sign;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + str[i++] - '0';
	if (sign)
		nbr *= -1;
	return (nbr);
}

#include <stdio.h>
int main(void)
{
	printf("%d", ft_atoi("-+ -++54kiook42"));
	return (0);
}
