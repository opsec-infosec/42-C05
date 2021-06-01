#include <stdio.h>
#include "../ex07/ft_find_next_prime.c"

int ft_find_next_prime(int nb);

int	main(void)
{
	printf("\nCalling ft_find_next_prime(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 2\n",ft_find_next_prime(0));
	printf("nb = -5		 | ret = %d		| Expected = 2\n",ft_find_next_prime(-5));
	printf("nb = 1		 | ret = %d		| Expected = 2\n",ft_find_next_prime(1));
	printf("nb = 2		 | ret = %d		| Expected = 2\n",ft_find_next_prime(2));
	printf("nb = 8		 | ret = %d		| Expected = 11\n",ft_find_next_prime(8));
	printf("nb = 20		 | ret = %d		| Expected = 23\n",ft_find_next_prime(20));
	printf("nb = 42		 | ret = %d		| Expected = 43\n",ft_find_next_prime(42));
	printf("nb = 2147483630		| ret = %d	| Expected = 2147483647\n",ft_find_next_prime(2147483630));
	
	return (0);
}