#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex07/ft_find_next_prime.c"

int ft_find_next_prime(int nb);

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
	printf("\nCalling ft_find_next_prime(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 2\n",ft_find_next_prime(0));
	printf("nb = -5		 | ret = %d		| Expected = 2\n",ft_find_next_prime(-5));
	printf("nb = 1		 | ret = %d		| Expected = 2\n",ft_find_next_prime(1));
	printf("nb = 2		 | ret = %d		| Expected = 2\n",ft_find_next_prime(2));
	printf("nb = 8		 | ret = %d		| Expected = 11\n",ft_find_next_prime(8));
	printf("nb = 20		 | ret = %d		| Expected = 23\n",ft_find_next_prime(20));
	printf("nb = 42		 | ret = %d		| Expected = 43\n",ft_find_next_prime(42));
	printf("nb = 2147483630		| ret = %d	| Expected = 2147483647\n",ft_find_next_prime(2147483630));
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