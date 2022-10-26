#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum = 0, i = 0;

float min = 0, max = 0, avg = 0;

int calc_avg(int arr[]);
int calc_max(int arr[]);
int calc_min(int arr[]);

int num_arr[10];

int main(){

	FILE *ptr;
	int ch;

    ptr = fopen("data.txt", "r");

    if (NULL == ptr) {
            printf("file can't be opened \n");
    }

    do {
        ch = fgetc(ptr);
        num_arr[i] = ch;
        i++;
    } while (ch != EOF);

	pid_t pid1, pid2, pid3;

	pid1 = fork();
	if(pid1 < 0){
		printf("creating child 1 error");
	}else if(pid1 == 0){
		printf("The average is %d\n", calc_avg(num_arr));
	}else{
		pid2 = fork();
		if(pid2 < 0){
			printf("creating child 2 error");
		}else if(pid2 == 0){
			printf("The Maximum is %d\n", calc_max(num_arr));
		}else{
			pid3 = fork();
			if(pid3 < 0){
				printf("creating child 3 error");
			}else if(pid3 == 0){
				printf("The Minimum is %d\n", calc_min(num_arr));
			}
		}
	}

	return 0;
}

int calc_avg(int arr[]){

	for(i=0; i<10; i++){
		sum = sum + arr[i];
	}

	return sum/10;
}

int calc_max(int arr[]){

	max = arr[0];

	for(i=0; i<10; i++){
		if(max<arr[i]){
			max = arr[i];
		}
	}

	return max;

}

int calc_min(int arr[]){

        min = 99999;

        for(i=0; i<10; i++){
                if(min>arr[i]){
                        min = arr[i];
                }
        }

        return min;

}
