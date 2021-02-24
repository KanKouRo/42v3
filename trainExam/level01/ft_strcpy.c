#include <unistd.h>
#include <stdio.h>
char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*int main(void)
{
	char str[] = "FT_STRCPY MGL";
	char tab[] = "CHURROS";
	printf("%s", ft_strcpy(tab, str));
	return (0);
}*/
