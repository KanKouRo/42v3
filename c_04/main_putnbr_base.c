/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:59:43 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/17 10:00:40 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putnbr_base(int nbr, char *base);

int main ()
{
	//char base[] = "01";
	printf("%d", ft_putnbr_base(12, "0123456789ABCDEF"));
	return (0);
}
