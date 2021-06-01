#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex03/ft_recursive_power.c"

int ft_recursive_power(int nb, int power);

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
	printf("\nCalling ft_recursive_power(int nb, int power);\n\n");
	printf("nb = 0	| power = 0	| ret = %d		| Expected = 1\n",ft_recursive_power(0,0));
	printf("nb = 2	| power = -1	| ret = %d		| Expected = 0\n",ft_recursive_power(2,-1));
	printf("nb = 5	| power = 5 	| ret = %d		| Expected = 3125\n",ft_recursive_power(5,5));
	printf("nb = 10	| power = 20	| ret = %d	| Expected = 1661992960\n\n",ft_recursive_power(10,20));
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
