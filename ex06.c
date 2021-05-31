#include <stdio.h>
#include "../ex06/ft_is_prime.c"

int ft_is_prime(int nb);

int	main(void)
{
	printf("\nCalling ft_is_prime(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 0\n",ft_is_prime(0));
	printf("nb = -5		 | ret = %d		| Expected = 0\n",ft_is_prime(-5));
	printf("nb = 1		 | ret = %d		| Expected = 0\n",ft_is_prime(1));
	printf("nb = 2		 | ret = %d		| Expected = 1\n",ft_is_prime(2));
	printf("nb = 7		 | ret = %d		| Expected = 1\n",ft_is_prime(7));
	printf("nb = 19		 | ret = %d		| Expected = 1\n",ft_is_prime(19));
	printf("nb = 23		 | ret = %d		| Expected = 1\n",ft_is_prime(23));
	printf("nb = 2147483647		 | ret = %d		| Expected = 1\n",ft_is_prime(2147483647));
	
	return (0);
}