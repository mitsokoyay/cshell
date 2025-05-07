
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define DELIM " \t\r\n\a"

void parse_input(char *input, char **args){
    char *tok = strtok(input, DELIM);
    int i = 0;
    while(tok != NULL){
        args[i] = tok;
        printf("%s\n", tok);
        tok = strtok(NULL, DELIM);
        i++;
    }
   args[i] = NULL;
   /*
   for(int j = 0; j < i; j++){
       printf("%s\n", args[j]);
   }
   pid_t pid = fork();
   if(pid == 0){
       execvp(args[0], args);
   }
   else if(pid > 0){
       wait(NULL);
   }
   */


}

void run_process(char **args){

    pid_t run = fork();
    printf("%d\n", run);

    if(run == 0){
        printf("running execvp\n");
        execvp(args[0], args);
    }
    else if(run > 0){
        printf("waiting\n");
        wait(NULL);
    }
}



void forkts(){
    pid_t p = fork();
    printf("Hello world! Process ID = %d,\n", getpid());
}

int main(){
    char input[MAX_INPUT];
    char *tok;
    while(1){
        printf("sillyshell :3 >> ");
        fgets(input, MAX_INPUT, stdin);
        printf("Echoing: %s", input);
        char *args[MAX_ARGS];
        parse_input(input, args);
        run_process(args);
    }
    return 0;
}
