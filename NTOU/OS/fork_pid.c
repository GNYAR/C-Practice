#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid0, pid1;
  pid0 = fork();
  if (pid0 == 0)
  {
    pid1 = getpid();
    printf("A = %d\n", pid0); // 0
    printf("B = %d\n", pid1); // 501
  }
  else
  {
    pid1 = getpid();
    printf("C = %d\n", pid0); // 501
    printf("D = %d\n", pid1); // 500
  }
}
