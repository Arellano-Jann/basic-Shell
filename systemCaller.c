#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <sys/stat.h>


int executeCommand(char* []);
void changeDirectories(char*);
int parseInput(char *input, char *splitWords[]);

// 30
int main(){
    while (1){

    }
}

// 20
int executeCommand(char* []){

}

// 5
void changeDirectories(char*){
    if (chdir(char*) != 0){
        printf("Path Not Found!")
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