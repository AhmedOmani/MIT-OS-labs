#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc , char *argv[]) {

	if (argc != 2) {
		fprintf(2 , "Argument passed issue!\n") ;
		exit(1) ;
	}

	int ticks = atoi(argv[1]);
	sleep(ticks) ;
	return 0 ;
}


