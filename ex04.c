#include <stdio.h>
#include "../ex04/ft_fibonacci.c"

int ft_fibonacci(int index);

int	main(void)
{
	
	printf("\nCalling ft_fibonacci(int index);\n\n");
	printf("index = 0	 | ret = %d		| Expected = 0\n",ft_fibonacci(0));
	printf("index = -743	 | ret = %d		| Expected = -1\n",ft_fibonacci(-1));
	printf("index = 2	 | ret = %d		| Expected = 1\n",ft_fibonacci(2));
	printf("index = 3	 | ret = %d		| Expected = 2\n",ft_fibonacci(3));
	printf("index = 9	 | ret = %d		| Expected = 34\n",ft_fibonacci(9));
	printf("index = 15	 | ret = %d		| Expected = 610\n\n",ft_fibonacci(15));
	
	return (0);
}