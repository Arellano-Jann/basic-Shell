#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <sys/stat.h>

// 20
int executeCommand(char* cmd[]){
    pid_t pid = fork();

    if (pid == -1){ // if unsuccessful
        printf("Error in creating child process!");
        return 1;
    }
    
    if (pid == 0){ // Child successfully created
        if (execvp(cmd[0], cmd) == -1){ // if unsuccessful. code has side effects
            printf("Command Not Found!");
            return 1;
        }
    }
    else if (waitpid(pid, NULL, 0) == -1){// can also be waitpid(pid, &status, 0) // if unsuccessful
        printf("Error in waiting for child process!");
        return 1;
    }
    return 0;
}

// 5
void changeDirectories(char* path){
    if (chdir(path) != 0){
        printf("Path Not Found!");
    }
}

int parseInput(char *input, char *splitWords[]);

// 30
int main(){
    while (1){

    }
}


int parseInput(char *input, char *splitWords[]){
    int wordInd = 0;
    splitWords[0] = strtok(input, " \n");
    while(splitWords[wordInd] != NULL){
        splitWords[++wordInd] = strtok(NULL, " \n");
    }
    return wordInd;
}