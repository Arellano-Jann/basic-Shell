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
        printf("Error in creating child process!\n");
        return 1;
    }
    
    if (pid == 0){ // Child successfully created
        if (execvp(cmd[0], cmd) == -1){ // if unsuccessful. code has side effects
            printf("Command Not Found!\n");
            return 1;
        }
    }
    else if (waitpid(pid, NULL, 0) == -1){// can also be waitpid(pid, &status, 0) // if unsuccessful
        printf("Error in waiting for child process!\n");
        return 1;
    }
    return 0;
}

// 5
void changeDirectories(char* path){
    if (chdir(path) != 0){
        printf("Path Not Found!\n");
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

// 30
int main(){
    char cliInput[1024], *cmd[1024];
    int inp = 0;

    while (1){
        printf("exampleShell888000855$ ");
        fgets(cliInput, 1024, stdin);
        inp = parseInput(cliInput, cmd);
        if (inp == 0) continue; // if empty input, continue

        char* command = cmd[0];
        if (strcmp(command, "exit") == 0){
            exit(0);
        }
        else if (strcmp(command, "cd") == 0){
            changeDirectories(cmd[1]);
        }
        else{
            int failed = executeCommand(cmd);
            if (failed){
                printf("Failed!\n");
                exit(1);
            }
        }

    }
}


