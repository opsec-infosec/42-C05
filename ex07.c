#include <stdio.h>
#include "../ex07/ft_find_next_prime.c"

int ft_find_next_prime(int nb);

int	main(void)
{
	printf("\nCalling ft_is_prime(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 0\n",ft_find_next_prime(0));
	printf("nb = -5		 | ret = %d		| Expected = 0\n",ft_find_next_prime(-5));
	printf("nb = 1		 | ret = %d		| Expected = 0\n",ft_find_next_prime(1));
	printf("nb = 2		 | ret = %d		| Expected = 5\n",ft_find_next_prime(2));
	printf("nb = 7		 | ret = %d		| Expected = 11\n",ft_find_next_prime(7));
	printf("nb = 19		 | ret = %d		| Expected = 23\n",ft_find_next_prime(19));
	printf("nb = 41		 | ret = %d		| Expected = 43\n",ft_find_next_prime(41));
	printf("nb = 2147483629		 | ret = %d		| Expected = 2147483647\n",ft_find_next_prime(2147483629));
	
	return (0);
}