/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:21:22 by ngomis            #+#    #+#             */
/*   Updated: 2021/03/31 16:31:54 by ngomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int        ft_charset(char c, char *charset)
{
    int    i;

    i = -1;
    while (charset[++i])
        if (charset[i] == c)
            return (1);
    return (0);
}

int        ft_sizeof_word(char *str, char *charset)
{
    int size;

    size = 0;
    while (*str && !ft_charset(*str, charset))
    {
        ++size;
        ++str;
    }
    return (size);
}

int        ft_count_word(char *str, char *charset)
{
    int words;
    int state;

    words = 0;
    state = 1;
    while (*str)
    {
        if (ft_charset(*str, charset))
            state = 1;
        else
        {
            if (state == 1)
                ++words;
                state = 0;
        }
            ++str;
    }
    return (words);
}

char    **ft_split(char *str, char *charset)
{
    int index;
    int i;
    int words;
    char **ret;

    words = ft_count_word(str, charset);
    ret = (char **)malloc(sizeof(char *) * words + 1);
    index = -1;
    while (++index < words)
    {
        while (*str && ft_charset(*str, charset))
            ++str;
        ret[index] = malloc(sizeof(char) * ft_sizeof_word(str, charset) + 1);
        i = 0;
        while (*str && !ft_charset(*str, charset))
            ret[index][i++] = *str++;
        ret[index][i] = 0;
    }
    ret[index] = 0;
    return (ret);
}

int     main(int ac, char **av)
{
        char **ret;
        (void)ac;

        for (ret = ft_split(av[1], av[2]); *ret; ret++)
                printf("%s\n",*ret);
        return 0;
}
