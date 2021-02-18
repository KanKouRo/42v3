/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:51:33 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/18 09:59:44 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int nbr;

	nbr = 1;
	if (power < 0)
		return (0);
	if (power > 0)
		nbr = nb * ft_recursive_power(nb, power - 1);
	return (nbr);
}
