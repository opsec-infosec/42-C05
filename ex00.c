#include <stdio.h>
#include "../ex00/ft_iterative_factorial.c"

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("\n... You learn more from failure than from success ...\n\n");
	printf("Calling ft_recursive_factorial(int nb);\n");
	printf("nb = -1 | ret = %d		| Expected = 0\n",ft_interative_factorial(-1));
	printf("nb =  0 | ret = %d		| Expected = 1\n",ft_interative_factorial(0));
	printf("nb = 10 | ret = %d		| Expected = 3628800\n",ft_interative_factorial(10));
	printf("nb = 20 | ret = %d	| Expected = -288522240\n\n",ft_interative_factorial(17));
	
	return (0);
}