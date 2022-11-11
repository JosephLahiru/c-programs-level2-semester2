#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
#include <semaphore.h>

void *deposit(void *amount);
void *withdraw(void *amount);
void menu();

float bank_balance = 0.0;
float amount;

sem_t semaphore;

int main(){
	int op;

	do{
		menu();
		sem_init(&semaphore, 1, 1);
		printf("\nEnter Option: ");
		scanf("%d", &op);
		printf("----------------------------\n");

		switch(op){
			case 1:
				printf("Please enter the deposit amount : ");
				scanf("%f", &amount);

				pthread_t deposit_thread;
				pthread_create(&deposit_thread, NULL, deposit, &amount);
				pthread_join(deposit_thread, NULL);
				//deposit
				break;
			case 2:
				printf("Please enter the withdraw amount : ");
				scanf("%f", &amount);

				pthread_t withdraw_thread;
				pthread_create(&withdraw_thread, NULL, withdraw, &amount);
				pthread_join(withdraw_thread, NULL);
				//withdraw
				break;
			case 3:
				printf("Current Account Balance : %.2f\n", bank_balance);
				//Check Balance
				break;
			case 4:
				printf("Exitting...\n");
				//exit
				sem_destroy(&semaphore);
				break;
			default:
				printf("\nPlease choose correct option!!!\n");
		}
	}
	while(op!=4);

	return 0;
}

void *deposit(void *amt){
	sem_wait(&semaphore);
	bank_balance = bank_balance + *(float *)amt;
	sem_post(&semaphore);
	return 0;
}

void *withdraw(void *amt){
	sem_wait(&semaphore);
	if(*(float *)amt > bank_balance){
		printf("\nWithdrawal limit reached!!!\nWithdrawable amount : %.2f\n\n", bank_balance);
		bank_balance = 0.0;
	}else{
		bank_balance = bank_balance - *(float *)amt;
	}
	sem_post(&semaphore);
	return 0;
}

void menu(){
	printf("\n---- Banking System ---- \n");
	printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
	printf("----------------------------\n");
}
