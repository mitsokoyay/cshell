#include <stdio.h>
#include <unistd.h>


int main(){
    pid_t silly = fork();
    printf("%d\n", silly);
    char *fastfetch[] = {"fastfetch", NULL};
    fork();
    execvp(fastfetch[0], fastfetch );
    return 0;

}
