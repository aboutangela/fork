#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  printf("parent process \n");
  int one = fork();
  int two = fork();
  if(getpid() == one){
    printf("one pid: %d \n", getpid());
    sleep(1);
    printf("one finished \n");
    return 1;
  }
  if(getpid() == two){
    printf("two pid: %d \n", getpid());
    sleep(2);
    printf("one finished \n");
    return 2;
  }
  int s;
  wait(s);
  printf("completed child pid: %d, seconds asleep: %d \n")
  return 0;
}

