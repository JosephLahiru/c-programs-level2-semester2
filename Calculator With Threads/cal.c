#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float add(float x, float y);
float substract(float x, float y);
float multiply(float x, float y);
float devide(float x, float y);

int main(){

    int op;
    float x, y;

    pid_t pid1, pid2, pid3, pid4;

    do{
        printf("\n------- Basic Calculator -------\n\n");
        printf("\t1. Add\n\t2. Substract\n\t3. Multiply\n\t4. Devide\n\t5. Exit\n\n");
        printf("Please select an option : ");

        scanf("%d", &op);

        if(op!=5){
            printf("Please enter value 1: ");
            scanf("%f", &x);
            printf("Please enter value 2: ");
            scanf("%f", &y);
        }

        pid1 = fork();
        if(pid1 < 0){
            printf("\ncreating child 1 error.\n");
        }else if(pid1 == 0 && op == 1){
            printf("\nThe value after adding is %.2f\n", add(x, y));
        }else{
            pid2 = fork();
            if(pid2 < 0){
                printf("\ncreating child 2 error.\n");
            }else if(pid2 == 0 && op == 2){
                printf("\nThe value after substracting is %.2f\n", substract(x, y));
            }else{
                pid3 = fork();
                if(pid3 < 0){
                    printf("\ncreating child 3 error.\n");
                }else if(pid3 == 0  && op == 3){
                    printf("\nThe value after multiplying is %.2f\n", multiply(x, y));
                }else{
                    pid4 = fork();
                    if(pid4 < 0 ){
                        printf("\ncreating child 4 error.\n");
                    }else if(pid4 == 0  && op == 4){
                        printf("\nThe value after substracting is %.2f\n", devide(x, y));
                    }
                }
            }
        }
        
    }while(op!=5);

    return 0;
}

float add(float x, float y){
    return (x+y);
}

float substract(float x, float y){
    return (x-y);
}

float multiply(float x, float y){
    return (x*y);
}

float devide(float x, float y){
    return (x/y);
}