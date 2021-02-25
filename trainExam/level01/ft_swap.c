void	ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*#include <stdio.h>
int main()
{
	int a = 5;
	int b = 8;
	printf("%d || %d \n", a, b);
	ft_swap(&a, &b);
	printf("%d || %d \n", a, b);
	return (0);
}*/
