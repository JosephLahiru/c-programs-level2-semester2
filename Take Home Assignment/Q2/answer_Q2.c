#include<stdio.h>

int main(){
    while(true){
        // Reader wants to enter the critical section
        wait(mutex);

        // The number of readers has now increased by 1
        read_count++;                          

        // there is atleast one reader in the critical section
        // this ensure no writer can enter if there is even one reader
        // thus we give preference to readers here
        if (read_count==1)     
            wait(rw_mutex);                    

        // other readers can enter while this current reader is inside 
        // the critical section
        signal(mutex);                   

        // current reader performs reading here
        wait(mutex);   // a reader wants to leave

        read_count--;

        // that is, no reader is left in the critical section,
        if (read_count == 0) 
            signal(rw_mutex);         // writers can enter

        signal(mutex); // reader leaves
    }

    return 0;
}
