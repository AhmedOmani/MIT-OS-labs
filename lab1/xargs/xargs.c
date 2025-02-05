#include "kernel/types.h" 
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h" 

#define MAX_LEN 512 

int main(int argc , char *argv[]) {

    if (argc < 2) {
        fprintf(2 , "Usage: xargs <command> [args...]\n") ;
        exit(1) ;
    }
    //for appending new args
    char *new_argv[MAXARG] ;
    //read stdin 
    char buffer[MAX_LEN] ;

    //copying command & args after xargs
    int i , n ;
    for (i = 1 ; i < argc && i < MAXARG - 1 ; i++) 
        new_argv[i - 1] = argv[i] ;

    //read input from stdin line by line
    while((n = read(0 , buffer , sizeof(buffer))) > 0) {
        buffer[n] = '\0' ;
        if (buffer[n - 1] == '\n') 
            buffer[n - 1] = '\0' ;

        // append stdin input as the last argument
        new_argv[i - 1] = buffer ;
        new_argv[i] = 0;

        if (fork() == 0) {
            exec(new_argv[0] , new_argv) ;
            fprintf(2 , "exec failed\n") ;
            exit(1) ;
        } 
        wait(0) ;
    } 
    return 0 ;
}
