int	ft_atoi(const char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;

	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("%d", ft_atoi(" \n  -+-5q \t "));
	write(1, " ", 1);
	printf("%d", atoi(" \n  -+-5q  \t"));
	return 0;
}
