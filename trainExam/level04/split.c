#include <stdlib.h>

int is_in_charset(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
            return (1);
    return (0);
}

char **split(char *str)
{
        int i;
        int j;
        int n;
        char **dest;

        i = 0;
        n = 0;
        if (!(dest = (char **) malloc(sizeof(char *) * 256)))
                return (NULL);
        while (is_in_charset(str[i]) == 1)
                i++;
        while (str[i] != '\0')
        {
                j = 0;
                if (!(dest[n] = (char *)malloc(sizeof(char) * 4096)))
                        return (NULL);
                while (is_in_charset(str[i]) == 0)
                	dest[n][j++] = str[i++];
                while(is_in_charset(str[i]) == 1)
                	i++;
                dest[n][j] = '\0';
                n++;
        }
        dest[n] = NULL;
        return (dest);
}

#include <stdio.h>

int main(void)
{
	char **tab;

 	tab =split("salut les amis comment ca va");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s\n", tab[5]);
}
