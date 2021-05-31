#include <stdio.h>
#include "../ex01/ft_recursive_factorial.c"

int	ft_recursive_factorial(int nb);

int	main(void)
{
	printf("\nCalling ft_recursive_factorial(int nb);\n\n");
	printf("nb = -1 | ret = %d		| Expected = 0\n",ft_recursive_factorial(-1));
	printf("nb =  0 | ret = %d		| Expected = 1\n",ft_recursive_factorial(0));
	printf("nb = 10 | ret = %d		| Expected = 3628800\n",ft_recursive_factorial(10));
	printf("nb = 20 | ret = %d	| Expected = -288522240\n\n",ft_recursive_factorial(17));
	
	return (0);
}