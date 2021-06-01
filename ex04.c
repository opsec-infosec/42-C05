#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex04/ft_fibonacci.c"

int ft_fibonacci(int index);

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
	printf("\nCalling ft_fibonacci(int index);\n\n");
	printf("index = 0	 | ret = %d		| Expected = 0\n",ft_fibonacci(0));
	printf("index = -743	 | ret = %d		| Expected = -1\n",ft_fibonacci(-743));
	printf("index = 2	 | ret = %d		| Expected = 1\n",ft_fibonacci(2));
	printf("index = 3	 | ret = %d		| Expected = 2\n",ft_fibonacci(3));
	printf("index = 9	 | ret = %d		| Expected = 34\n",ft_fibonacci(9));
	printf("index = 15	 | ret = %d		| Expected = 610\n\n",ft_fibonacci(15));
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