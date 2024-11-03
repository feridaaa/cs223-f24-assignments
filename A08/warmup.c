/*--------------------------
 * Author: Ferida Mohammed
 * Date: 11/1/24
 * Discription:
 ---------------------------*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;
  printf("%04d] A0\n", getpid());
  pid = fork();

  if (pid) {   		// parent process
    printf("%04d] B0\n", getpid());

    pid = fork();
    if (pid) {   	//parent process
      printf("%04d] C0\n", getpid()); 
    }
    else {		//child process
      printf("%04d] C1\n", getpid());
    }
  }

  else {		// child process
    printf("%04d] B1\n", getpid());
  }
  printf("%04d] Bye\n", getpid());

  return 0;
}
