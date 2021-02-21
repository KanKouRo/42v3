/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:18:28 by ngomis            #+#    #+#             */
/*   Updated: 2021/02/21 14:11:54 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *str;
    int j;
    int i;

    j = 0;
    while (src[j] != '\0')
        j++;
    str = malloc(sizeof(str) * (j + 1));
    i = 0;
    while (src[i] != '\0')
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    free(str);
    return(str);
}

int main(void)
{
    printf("%s", strdup("CouCou\n"));
    printf("%s", ft_strdup("Salut Monde\n"));
    return (0);
}
