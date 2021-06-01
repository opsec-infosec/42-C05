#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex05/ft_sqrt.c"

int ft_sqrt(int nb);

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
	printf("\nCalling ft_sqrt(int nb);\n\n");
	printf("nb = 0		 | ret = %d		| Expected = 0\n",ft_sqrt(0));
	printf("nb = -3		 | ret = %d		| Expected = 0\n",ft_sqrt(-3));
	printf("nb = 1		 | ret = %d		| Expected = 1\n",ft_sqrt(1));
	printf("nb = 2		 | ret = %d		| Expected = 0\n",ft_sqrt(2));
	printf("nb = 2147483646	 | ret = %d		| Expected = 0\n",ft_sqrt(2147483646));
	printf("nb = 30591961	 | ret = %d		| Expected = 5531\n",ft_sqrt(30591961));
	printf("nb = 256128016 	 | ret = %d		| Expected = 16004\n",ft_sqrt(256128016));
	printf("nb = 267747769	 | ret = %d		| Expected = 16363\n",ft_sqrt(267747769));
	printf("nb = 2147395600	 | ret = %d		| Expected = 46340\n",ft_sqrt(2147395600));
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

