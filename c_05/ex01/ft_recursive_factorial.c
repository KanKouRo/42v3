/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:18 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/18 09:41:32 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int nbr;

	nbr = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
		nbr = nb * ft_recursive_factorial(nb - 1);
	return (nbr);
}
