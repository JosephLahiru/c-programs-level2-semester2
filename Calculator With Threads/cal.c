#include<stdio.h>
#include<stdlib.h>

void add(float x, float y);
void substract(float x, float y);
void multiply(float x, float y);
void devide(float x, float y);

int main(){

    int op;
    float x, y;

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

        switch (op)
        {
            case 1:
                //add
                add(x, y);
                break;
            case 2:
                //Subtract
                substract(x, y);
                break;
            case 3:
                //multiply
                multiply(x, y);
                break;
            case 4:
                //devide
                devide(x, y);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please check your selected item!!");
                break;
        }

    }while(op!=5);

    return 0;
}

void add(float x, float y){
    printf("\nValue after adding %.2f\n", x+y);
}

void substract(float x, float y){
    printf("\nValue after substracting %.2f\n", x-y);
}

void multiply(float x, float y){
    printf("\nValue after multiplying %.2f\n", x*y);
}

void devide(float x, float y){
    printf("\nValue after deviding %.2f\n", x/y);
}