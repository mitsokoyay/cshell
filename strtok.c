#include <string.h>
#include <stdio.h>

int main(){
    char str[] = "Hello world;How-are You";
    char *token;

    token = strtok(str, " ;-");

    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ;-");
    }
    return 0;
}
