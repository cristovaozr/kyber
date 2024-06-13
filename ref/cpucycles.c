#include <stdint.h>
#include "cpucycles.h"
#include <time.h>

uint64_t cpucycles_overhead(void) {
  uint64_t t0, t1, overhead = -1LL;
  unsigned int i;

  for(i=0;i<100000;i++) {
    t0 = cpucycles();
    __asm__ volatile ("");
    t1 = cpucycles();
    if(t1 - t0 < overhead)
      overhead = t1 - t0;
  }

  return overhead;
}

#if 1

inline uint64_t cpucycles(void)
{
  static struct timespec first_time = {.tv_sec = 0, .tv_nsec = 0};
  struct timespec tp;

  clock_gettime(CLOCK_REALTIME, &tp);
  if (first_time.tv_sec == 0) {
    first_time.tv_sec = tp.tv_sec;
    first_time.tv_nsec = tp.tv_nsec;
  }
  return (tp.tv_sec - first_time.tv_sec) * 1000000000 + (tp.tv_nsec - first_time.tv_nsec);
}

#endif
