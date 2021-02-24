/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:18:10 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/24 17:02:38 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	s_stock_str *s;
	
	if (!(*s = malloc(sizeof(s_stock_str) * )	
