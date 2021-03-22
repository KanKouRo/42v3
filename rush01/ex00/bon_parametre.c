/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_parametre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:47:58 by cboutier          #+#    #+#             */
/*   Updated: 2021/03/21 11:29:37 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

int		bonparametre(int arc, char *arv)
{
	int i;

	i = 0;
	if (arc != 2)
		return (0);
	if (ft_strlen(arv) != 31)
		return (0);
	while (i <= 30)
	{
		if (!(arv[i] >= '1' && arv[i] <= '4'))
			return (0);
		i += 2;
	}
	i = 1;
	while (i <= 29)
	{
		if (arv[i] != ' ')
			return (0);
		i += 2;
	}
	return (1);
}
