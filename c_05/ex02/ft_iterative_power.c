/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:41:56 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/18 09:58:51 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int nbr;

	i = 0;
	nbr = nb;
	if (power < 0)
		return (0);
	while (i < power - 1)
	{
		nbr = (nbr * nb);
		i++;
	}
	return (nbr);
}
