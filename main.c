
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define DELIM " \t\r\n\a"


int pijpe(int *pipedes){

    int pjipe = pipe();
//    printf("TS has not been piped");
    return 0;
}



void parse_input(char *input, char **args){
    char *tok = strtok(input, DELIM);
    int i = 0;
    while(tok != NULL){
        if(strcmp(tok, "|")){
            pijpe(&i);
        }
        args[i] = tok;
        printf("%s\n", tok);
        tok = strtok(NULL, DELIM);
        i++;
    }
   args[i] = NULL;
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


int main(){
    char input[MAX_INPUT];
    char cwd[PATH_MAX];
    char *tok;
    char *wd = getcwd(input, sizeof(input));
    while(1){
        printf("sillyshell :3 %s >> ", wd);

        fgets(input, MAX_INPUT, stdin);
        printf("Echoing: %s", input);
        char *args[MAX_ARGS];
        parse_input(input, args);
        if(strcmp("cd", args[0]) == 0){
            if(args[1] == NULL){
                chdir("mitsoko");
            }
            else{
            chdir(args[1]);
            }
            continue;
        }

        if(strcmp("exit", args[0]) == 0){
            break;
        }
        run_process(args);



    }
    return 0;
}
