#include<stdio.h>

void add(float x, float y);
void substract(float x, float y);
void multiply(float x, float y);
void devide(float x, float y);

int main(){

    int op;

    do{
        printf("\n------- Basic Calculator -------\n\n");
        printf("\t1. Add\n\t2. Substract\n\t3. Multiply\n\t4. Devide\n\t5. Exit\n\n");
        printf("Please select an option : ");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
                //add
                break;
            case 2:
                //Subtract
                break;
            case 3:
                //multiply
                break;
            case 4:
                //devide
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

}

void subtract(float x, float y){

}

void multiply(float x, float y){

}

void devide(float x, float y){

}