#include <stdio.h>
#include "../ex05/ft_sqrt.c"

int ft_sqrt(int nb);

int	main(void)
{
	printf("\nCalling ft_sqrt(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 0\n",ft_sqrt(0));
	printf("nb = -3		 | ret = %d		| Expected = 0\n",ft_sqrt(-3));
	printf("nb = 3		 | ret = %d		| Expected = 0\n",ft_sqrt(3));
	printf("nb = 81		 | ret = %d		| Expected = 9\n",ft_sqrt(81));
	printf("nb = 729		 | ret = %d		| Expected = 27\n",ft_sqrt(729));
	printf("nb = 2147483647	 | ret = %d		| Expected = 0\n",ft_sqrt(2147483647));
	printf("nb = -2147483648	 | ret = %d		| Expected = 0\n",ft_sqrt(-2147483648));
	
	return (0);
}