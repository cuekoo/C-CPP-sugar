/******************************************************************************
 * This program demonstrates that SIGALRM can be used as a timer. If the delay
 * time is less than the interval, SIGALRM can guarantee that the interval to 
 * call the handler is always approximately the value we set to the timer.. 
 *
 * In real applications, replace the delay with your processing function.
 *
 * Liu Yuan. Nov 19, 2014
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> /* gettimeofday */
#include <signal.h>

struct timeval handler_start_pre;
struct timeval handler_start;
struct timeval delay_end;
int i;

static void sig_alarm(int signo)
{
    gettimeofday(&handler_start, (struct timezone*) 0);
    double handler_interv = (handler_start.tv_sec - handler_start_pre.tv_sec) + 
        ((handler_start.tv_usec - handler_start_pre.tv_usec) / 1000000.0F);
    handler_start_pre = handler_start;

    /* a loop delay less than interval*/
    for (i = 0; i < 10000000; i++);

    gettimeofday(&delay_end, (struct timezone*) 0);

    double delay_elapsed = (delay_end.tv_sec - handler_start.tv_sec) + 
        ((delay_end.tv_usec - handler_start.tv_usec) / 1000000.0F);

    printf("delay: %f  interval: %f\n", delay_elapsed, handler_interv);
}

int main() 
{
    useconds_t interval = 40000; /* 40ms */
    signal(SIGALRM, sig_alarm);
    gettimeofday(&handler_start_pre, 0);
    ualarm(interval, interval);
    while (1);

    return 0;
}
