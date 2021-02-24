/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:36:25 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/20 11:54:53 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*swap;

	i = 1;
	while (i < argc)
	{
		j = (i + 1);
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[i]) < 0)
			{
				swap = argv[i];
				argv[i] = argv[j];
				argv[j] = swap;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
