#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
  srand(time(NULL));
  printf("parent process \n");
  int one = fork();
  if(! one){
    int t1 = rand() % 15 + 5;
    printf("one pid: %d \n", getpid());
    sleep(t1);
    printf("one finished \n");
    return t1;
  }
  else{
    int two = fork();
    if(! two){
      int t2 = rand() % 3 + 5;
      printf("two pid: %d \n", getpid());
      sleep(t2);
      printf("two finished \n");
      return t2;
    }
    else{
      int s;
      int p = wait(&s);
      printf("completed child pid: %d, seconds asleep: %d \n", p, WEXITSTATUS(s));
      return 0;
    }
  }
}
