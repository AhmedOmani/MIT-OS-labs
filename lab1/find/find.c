#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"


void find(char *path , char *target) {
	int fd ;
	struct stat st ;
	struct dirent de ;
	char buf[512] , *p;

	if ((fd = open(path , 0)) < 0) {
		fprintf(2 , "find: cannot open %s\n" , path) ;
		retrun ;
	}

	if (fstat(fd , &st) < 0) {
		fprintf(2 , "find: cant get data of directory\n") ;
		return ;
	}
	
	while (read(fd , &de , sizeof(de)) == sizeof(de)) {
		//skip unused entries
		if (de.imun == 0) {
			continue ;
		}	
		//skip . & .. directories
		if (strcmp(de.name , ".") == 0 || strcmp(de.name , "..") == 0) {
			continue ;
		}
		//Construct the full path
		strcpy(buf , path) ;
		p = buf + strlen(buf) ;
		*p++ = '/' ;
		memmove(p , de.name , DIRSIZE) ;
		p[DIRSIZE] = 0 ;
		//check if the new entry matches the target
		if (strcmp(de.name , target) == 0) {
			printf("%s\n" , buf);
		}
		//Recursively search subdirectories
		if (st.type == T_DIR) {
			find(buf , target) ;
		}
	}
	close(fd) ;

}

int main(int argc , char *argv[]) {
	if (argc != 3) {
		fprintf(2 , "Usage: find <path> <target>\n") ;
		exit(1) ;
	}
	find(argv[1] , argv[2]) ;
	exit(0)

}
