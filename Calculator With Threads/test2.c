#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

struct value_struct{
    float val1;
    float val2;
};

void *add(void *a);

sem_t mutex;
float ans = 0;

int main(){

    int op=0;

    struct value_struct values;

    pthread_t add_id, sub_id, mul_id, div_id;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    sem_init(&mutex, 0, 1);

    do{
        printf("1. Add\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Value 1: ");
                scanf("%f", &values.val1);
                printf("Enter Value 2: ");
                scanf("%f", &values.val2);

                pthread_create(&add_id, &attr, add, (void*)&values);
                pthread_join(add_id, NULL);
                break;
        }

    }while(op!=5);
    
    return 0;
}

void *add(void *a){
    struct value_struct *vals = a;

    float x = vals->val1;
    float y = vals->val2;

    sem_wait(&mutex);
    ans = x+y;
    sem_post(&mutex);

    printf("\n\nout val : %.2f\n\n", ans);
}