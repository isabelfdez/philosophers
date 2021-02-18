#include <sys/time.h>
#include <stdio.h>

int main() {
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  suseconds_t a = current_time.tv_usec;
  time_t b = current_time.tv_sec;
  printf("milisec a = %ld time a : %ld\n", a, b);
  long long h = 0;
  while (h < 1000000000)
  {
      h++;
  }
  printf("Hello world\n");
  gettimeofday(&current_time, NULL);
  suseconds_t c = current_time.tv_usec;
  time_t d = current_time.tv_sec;
  printf("milisec c = %ld time c : %ld\n", c, d);
  c += (d - b) * 1000000;
  printf("time used : %ld\n", c - a);

  return 0;
}