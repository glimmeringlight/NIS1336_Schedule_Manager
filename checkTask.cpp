#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<vector>
#include<pthread.h>
#include"types.h"
#include"Tasks.h"


void *thread2(void * arg){
    printf("CheckTask begins!\n");
    int flag = 1;
    int check_interval = 5;

    //get args
    Thread_Arg* thread_arg_ptr = (Thread_Arg*)arg;
    pthread_mutex_t* mutex = thread_arg_ptr->mutex;
    User* user = thread_arg_ptr->user;

    std::vector<Task> tasklist;

    //checktask
    while(1){
        //read tasklist
        pthread_mutex_lock(mutex);
        loadTask(tasklist, user);
        pthread_mutex_unlock(mutex);

        //get current time
        time_t timep;
        time(&timep);

        printf("In the loop\n");

        sleep(check_interval);
    }

    return NULL;
    
}