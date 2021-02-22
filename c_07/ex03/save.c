/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:26:00 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/22 16:25:34 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_allocate(int size, char **strs, char *sep)
{
	int i;
	int nb_char;

	nb_char = 1;
	i = 0;
	while(i < size)
	{
		if (i == 0)
			nb_char = nb_char +ft_strlen(strs[i]);
		else
			nb_char = nb_char + ft_strlen(sep) + ft_strlen(strs[i]);
		i++;
	}
	return (malloc(sizeof(char) * nb_char));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int j;
	int n;
	char *dest;
	char *str;

	dest = ft_allocate(size, strs, sep);
	i = 0;
	n = 0;
	while(i < size)
	{
		j = 0;
		if (i != 0)
			while (sep[j] != '\0')
				dest[n++] = sep[j++];
		j = 0;
		str = strs[i];
		while(str[j] != '\0')
			dest[n++] = str[j++];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

int main(void)
{
	char strs[] = "hello";
    printf("%s", ft_strjoin(20, *strs, "-"));
	return (0);
}
