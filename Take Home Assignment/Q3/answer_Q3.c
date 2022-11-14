#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1

int fd[2], bytesRead;
char message [100];
void collatz_conjecture(int n);

int main(){

    pipe ( fd );

    int init_num;
    pid_t pid1;

    printf("Please enter the initial number : ");
    scanf("%d", &init_num);

    pid1= fork();

    if(pid1<0){
        printf("Child creation error !!!");
    }else if(pid1==0){
        collatz_conjecture(init_num);
    }else{
        close (fd[WRITE]);
        bytesRead = read ( fd[READ], message, 100);
        printf ( "Parent: Read %d bytes from pipe: %s\n", bytesRead, message);
        close ( fd[READ]);

        printf("\nEnd of Execution.\n");
    }

    return 0;
}

void collatz_conjecture(int n){

    char tagstr[60];
    int pos = 0;
    close (fd[READ]);

    while(n > 1){

        if(n % 2 == 0){
            n = n / 2;
            pos += sprintf(&tagstr[pos], ", %d", n);
        }
        else{
            n = n * 3 + 1;
            pos += sprintf(&tagstr[pos], ", %d", n);
        }
    }

    write (fd[WRITE], tagstr, strlen ( tagstr) +1);
    close (fd[WRITE]);
}