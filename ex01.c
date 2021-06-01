#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex01/ft_recursive_factorial.c"

int	ft_recursive_factorial(int nb);

int func_done = 0;
int timer_done = 0;

void *timer(void *var)
{
	var = 0x00;
	sleep(5);
	timer_done = 1;
	return (0);
}

void *execute(void *var)
{
	var = 0x00;
	printf("\nCalling ft_recursive_factorial(int nb);\n\n");
	printf("nb = -1 | ret = %d		| Expected = 0\n",ft_recursive_factorial(-1));
	printf("nb =  0 | ret = %d		| Expected = 1\n",ft_recursive_factorial(0));
	printf("nb = 10 | ret = %d		| Expected = 3628800\n",ft_recursive_factorial(10));
	printf("nb = 20 | ret = %d	| Expected = -288522240\n\n",ft_recursive_factorial(17));
	func_done = 1;
	return (0);
}
int	main(void)
{
	pthread_t threadId;
	pthread_t timerId;
	int	threadId_Sig;
	
	threadId_Sig = pthread_create(&threadId, NULL, execute,  NULL);
	pthread_create(&timerId, NULL, timer, NULL);

	while (1) {
		if (timer_done) {
			pthread_cancel(threadId);
			printf("*** TIMEOUT ***\n");
			return (1);
		}
		if (func_done)
		{
			pthread_cancel(timerId);
			return (0);
		}
	}
	return (0);
}