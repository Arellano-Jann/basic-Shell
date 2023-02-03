#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <sys/stat.h>

// 30
int main(){

}

// 20
int executeCommand(char* []){

}

// 5
void changeDirectories(char*){
    
}

int parseInput(char *input, char *splitWords[]){
    int wordInd = 0;
    splitWords[0] = strtok(input, " \n");
    while(splitWords[wordInd] != NULL){
        splitWords[++wordInd] = strtok(NULL, " \n");
    }
    return wordInd;
}