#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *add(void *a) ;
void *substract(void *a) ;
void *multiply(void *a) ;
void *devide(void *a) ;

struct value_struct {
    float val1;
    float val2;
};

sem_t mutex;
float ans = 0;

void main() {
  int op;

  struct value_struct values;

  pthread_t add_id, sub_id, mul_id, div_id;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  sem_init(&mutex, 0, 1);
  do {
    printf("1. Add\n");
    printf("2. Substract\n");
    printf("3. Multiply\n");
    printf("4. Devide\n");
    printf("5. Exit\n");
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
      case 2:
        printf("Enter Value 1: ");
        scanf("%f", &values.val1);
        printf("Enter Value 2: ");
        scanf("%f", &values.val2);

        pthread_create(&sub_id, &attr, substract, (void*)&values);
        pthread_join(sub_id, NULL);
        break;
      case 3:
        printf("Enter Value 1: ");
        scanf("%f", &values.val1);
        printf("Enter Value 2: ");
        scanf("%f", &values.val2);

        pthread_create(&mul_id, &attr, multiply, (void*)&values);
        pthread_join(mul_id, NULL);
        break;
      case 4:
        printf("Enter Value 1: ");
        scanf("%f", &values.val1);
        printf("Enter Value 2: ");
        scanf("%f", &values.val2);

        pthread_create(&div_id, &attr, devide, (void*)&values);
        pthread_join(div_id, NULL);
        break;
      case 5:
        exit(0);
      default:
        printf("Wrong option\n");
    }
  } while (1);
}

void *add(void *a) {
  struct value_struct *vals = a;

  float x = vals->val1;
  float y = vals->val2;

  sem_wait(&mutex);
  ans = x+y;
  sem_post(&mutex);
  printf("\nValue after addition: %.2f\n\n", ans);
}

void *substract(void *a) {
  struct value_struct *vals = a;

  float x = vals->val1;
  float y = vals->val2;
  
  sem_wait(&mutex);
  ans = x-y;
  sem_post(&mutex);
  printf("\nValue after substraction: %.2f\n\n", ans);
}

void *multiply(void *a) {
  struct value_struct *vals = a;

  float x = vals->val1;
  float y = vals->val2;

  sem_wait(&mutex);
  ans = x*y;
  sem_post(&mutex);
  printf("\nValue after multiplication: %.2f\n\n", ans);
}

void *devide(void *a) {
  struct value_struct *vals = a;

  float x = vals->val1;
  float y = vals->val2;

  sem_wait(&mutex);
  ans = x/y;
  sem_post(&mutex);
  printf("\nValue after divition: %.2f\n\n", ans);
}