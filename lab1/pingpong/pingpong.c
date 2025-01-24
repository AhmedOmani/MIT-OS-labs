#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc , char *argv[]) {

	int fd1[2] , fd2[2] ;
	char byte = 'a' ;

	if (pipe(fd1) == -1 || pipe(fd2) == -1) {
		fprintf(2 , "pipe failed\n") ;
	       	exit(1) ;	
	}

	int id = fork() ;
	if (id == -1) {
		fprintf(2 , "fork failed\n") ;
		exit(1);
	}

	if (id == 0) { // child process
		//GET from parent
		close(fd1[1]) ;
		close(fd2[0]) ;

		char received ;
		read(fd1[0] , &received , 1) ;
		close(fd1[0]) ;

		printf("%d: received ping\n" , getpid()) ;

		//POST to parent
		write(fd2[1] , &received , 1) ;
		close(fd2[1]) ;

		exit(0) ;

	} else {
		//POST to child 
		close(fd1[0]) ;
		close(fd2[1]) ;
		
		write(fd1[1] , &byte , 1) ;
		close(fd1[1] ;

		//GET from child 
		char received ;
		read(fd2[0] , &received , 1) ;

		printf("%d: received pong\n" , getpid()) ;
	}


}
