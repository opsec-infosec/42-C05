#include <stdio.h>
#include "../ex02/ft_iterative_power.c"

int ft_iterative_power(int nb, int power);

int	main(void)
{
	
	printf("\nCalling ft_iterative_power(int nb, int power);\n\n");
	printf("nb = 0	| power = 0	| ret = %d		| Expected = 1\n",ft_iterative_power(0,0));
	printf("nb = 2	| power = -1	| ret = %d		| Expected = 0\n",ft_iterative_power(2,-1));
	printf("nb = 5	| power = 5 	| ret = %d		| Expected = 3125\n",ft_iterative_power(5,5));
	printf("nb = 10	| power = 20	| ret = %d	| Expected = 1661992960\n\n",ft_iterative_power(10,20));

	

	return (0);
}