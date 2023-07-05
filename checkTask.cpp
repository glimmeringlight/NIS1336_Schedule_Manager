#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<vector>
#include<pthread.h>
#include"types.h"

int checkTask(pthread_mutex_t* mutex){
    std::vector<Task> tasklist;

    //get tasklist
    pthread_mutex_lock(mutex);
    

    struct tm *now_time;

    //get current time
    time_t n;
    time(&n);
    now_time = localtime(&n);
    

}

void *thread2(void * arg){
    printf("CheckTask begins!\n");
    int flag = 1;
    int check_interval = 60;

    //get mutex
    pthread_mutex_t* mutex = (pthread_mutex_t*)arg;

    while(flag){
        checkTask(mutex);   //arg mutex is a ptr
        sleep(check_interval);
    }

    return;
    
}

int main(){
    thread2();

    return 0;
}