#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define DT_PERIOD_S 0L
#define DT_PERIOD_US 100000L
#define DT_WAIT_S 0L
#define DT_WAIT_US 500000L
#define NUM_SLICES 100

int cnt_tick = 0;     // Global tick counter
struct timespec tP_0; // Global start timestamp

void interrupt_service_routine(int signum) {
  struct timespec t_Start_isr;
  clock_gettime(CLOCK_REALTIME, &t_Start_isr);
  printf("\n>%10ld %9ld ns -   -     Tick %i", t_Start_isr.tv_sec - tP_0.tv_sec,
         t_Start_isr.tv_nsec, cnt_tick);
  cnt_tick++;
}

int main(void) {
  struct itimerval itval;
  int ret;

  // Setup the timer
  itval.it_interval.tv_sec = DT_PERIOD_S;
  itval.it_interval.tv_usec = DT_PERIOD_US;
  itval.it_value.tv_sec = DT_WAIT_S;
  itval.it_value.tv_usec = DT_WAIT_US;

  // Setup sigaction
  struct sigaction mysigaction;
  sigemptyset(&mysigaction.sa_mask);
  mysigaction.sa_handler = interrupt_service_routine;
  mysigaction.sa_flags = SA_RESTART;

  sigaction(SIGALRM, &mysigaction, NULL);

  // Start the timer
  ret = setitimer(ITIMER_REAL, &itval, NULL);
  if (ret) {
    perror("timer init failed");
    return ret;
  }

  // Capture time zero and print
  clock_gettime(CLOCK_REALTIME, &tP_0);
  printf("\n>%10ld %9ld ns -   -    Tick %i", tP_0.tv_sec, tP_0.tv_nsec,
         cnt_tick);

  // Loop until done
  while (cnt_tick < NUM_SLICES)
    ;

  printf("\n");
  return 0;
}
