#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]){


  //print hello world through a pipe! To child!
 
  char hello[] = "Happy mashujaa day!!\n";
  char c;

  int pfd[2]; 
  

  pid_t cpid1;
  pid_t cpid2;
  pid_t cpid3;
  pid_t cpid4;
  pid_t cpid5; 
  int status;

  //open a pipe, pfd[0] for reading, pfd[1] for writing
  if ( pipe(pfd) < 0){
    perror("pipe");
    return 1;
  }

  cpid1 = fork();
  
  

  if( cpid1 == 0 ){
    /* CHILD */

    //close the writing end in child
    close(pfd[1]);
	printf("\n\nthis is child 1 and my parent told me to print: \n");
    //try and read 1 byte from pipe, write byte stdout
    while( read(pfd[0], &c, 1) > 0){
      write(1, &c,1); 
    }

    //close pipe
    close(pfd[0]);

    _exit(0);    
  }else if ( cpid1 > 0){
    /* PARENT */

    //close reading end in parent
    close(pfd[0]);

    //write hello world to pipe
    write(pfd[1], hello, strlen(hello));

    //close the pipe
    close(pfd[1]);

    //wait for child
    wait(&status);

if ( pipe(pfd) < 0){
    perror("pipe");
    return 1;
  }
	cpid2 = fork();

if( cpid2 == 0 ){
    /* CHILD */

    //close the writing end in child
    close(pfd[1]);
	printf("\n\nthis is child 2 and my parent told me to print: \n");
    //try and read 1 byte from pipe, write byte stdout
    while( read(pfd[0], &c, 1) > 0){
      write(1, &c,1); 
    }

    //close pipe
    close(pfd[0]);

    _exit(0);    
  }else if ( cpid2 > 0){
    /* PARENT */

    //close reading end in parent
    close(pfd[0]);

    //write hello world to pipe
    write(pfd[1], hello, strlen(hello));

    //close the pipe
    close(pfd[1]);

    //wait for child
    wait(&status);



if ( pipe(pfd) < 0){
    perror("pipe");
    return 1;
  }
cpid3 = fork();

if( cpid3 == 0 ){
    /* CHILD */

    //close the writing end in child
    close(pfd[1]);
	printf("\n\nthis is child 3 and my parent told me to print: \n");
    //try and read 1 byte from pipe, write byte stdout
    while( read(pfd[0], &c, 1) > 0){
      write(1, &c,1); 
    }

    //close pipe
    close(pfd[0]);

    _exit(0);    
  }else if ( cpid3 > 0){
    /* PARENT */

    //close reading end in parent
    close(pfd[0]);

    //write hello world to pipe
    write(pfd[1], hello, strlen(hello));

    //close the pipe
    close(pfd[1]);

    //wait for child
    wait(&status);

	//cpid2 = fork();

	if ( pipe(pfd) < 0){
    perror("pipe");
    return 1;
  }
cpid4 = fork();

if( cpid4 == 0 ){
    /* CHILD */

    //close the writing end in child
    close(pfd[1]);
	printf("\n\nthis is child 4 and my parent told me to print: \n");
    //try and read 1 byte from pipe, write byte stdout
    while( read(pfd[0], &c, 1) > 0){
      write(1, &c,1); 
    }

    //close pipe
    close(pfd[0]);

    _exit(0);    
  }else if ( cpid4 > 0){
    /* PARENT */

    //close reading end in parent
    close(pfd[0]);

    //write hello world to pipe
    write(pfd[1], hello, strlen(hello));

    //close the pipe
    close(pfd[1]);

    //wait for child
    wait(&status);

	//cpid2 = fork();
if ( pipe(pfd) < 0){
    perror("pipe");
    return 1;
  }
cpid5 = fork();

if( cpid5 == 0 ){
    /* CHILD */

    //close the writing end in child
    close(pfd[1]);
	printf("\n\nthis is child 5 and my parent told me to print: \n");
    //try and read 1 byte from pipe, write byte stdout
    while( read(pfd[0], &c, 1) > 0){
      write(1, &c,1); 
    }

    //close pipe
    close(pfd[0]);

    _exit(0);    
  }else if ( cpid5 > 0){
    /* PARENT */

    //close reading end in parent
    close(pfd[0]);

    //write hello world to pipe
    write(pfd[1], hello, strlen(hello));

    //close the pipe
    close(pfd[1]);

    //wait for child
    wait(&status);

	//cpid2 = fork();

  }else{
    /* ERROR */
    perror("fork");
    return 1;
  }
  }else{
    /* ERROR */
    perror("fork");
    return 1;
  }
  }else{
    /* ERROR */
    perror("fork");
    return 1;
  }


  }else{
    /* ERROR */
    perror("fork");
    return 1;
  }



  }else{
    /* ERROR */
    perror("fork");
    return 1;
  }


  return 0;
}

