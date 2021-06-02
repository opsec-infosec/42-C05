#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex06/ft_is_prime.c"

int ft_is_prime(int nb);

int func_done = 0;
int timer_done = 0;

void *timer(void *var)
{
	var = 0x00;
	sleep(10);
	timer_done = 1;
	return (0);
}

void *execute(void *var)
{
	var = 0x00;
	printf("\nCalling ft_is_prime(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 0\n",ft_is_prime(0));
	printf("nb = -5		 | ret = %d		| Expected = 0\n",ft_is_prime(-5));
	printf("nb = 1		 | ret = %d		| Expected = 0\n",ft_is_prime(1));
	printf("nb = 6		 | ret = %d		| Expected = 0\n",ft_is_prime(6));
	printf("nb = 8		 | ret = %d		| Expected = 0\n",ft_is_prime(8));
	printf("nb = 9		 | ret = %d		| Expected = 0\n",ft_is_prime(9));
	printf("nb = 2		 | ret = %d		| Expected = 1\n",ft_is_prime(2));
	printf("nb = 7		 | ret = %d		| Expected = 1\n",ft_is_prime(7));
	printf("nb = 19		 | ret = %d		| Expected = 1\n",ft_is_prime(19));
	printf("nb = 23		 | ret = %d		| Expected = 1\n",ft_is_prime(23));
	printf("nb = 2147483647	 | ret = %d		| Expected = 1\n",ft_is_prime(2147483647));
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