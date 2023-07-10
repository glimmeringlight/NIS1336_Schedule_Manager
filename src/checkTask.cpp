#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<vector>
#include<pthread.h>
#include"types.h"
#include"Tasks.h"
#include<iostream>


void *thread2(void * arg){
    printf("CheckTask begins!\n");
    int flag = 1;
    int check_interval = 60;
    int i = 0;

    //get args
    Thread_Arg* thread_arg_ptr = (Thread_Arg*)arg;
    pthread_mutex_t* mutex = thread_arg_ptr->mutex;
    User* user = thread_arg_ptr->user;
    struct tm *current_time;
    struct tm *task_time;
    double difft = 0;

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
        current_time = localtime(&timep);

        //check arriving tasks
        for(i = 0; i<tasklist.size(); ++i){
            
            task_time = localtime(&(tasklist[i].rem));
            
            if(task_time->tm_year != current_time->tm_year) continue;
            if(task_time->tm_mon != current_time->tm_mon) continue;
            if(task_time->tm_mday != current_time->tm_mday) continue;
            // day match if here
            difft = difftime(tasklist[i].rem, timep);

            if(difft > 0 && difft < 5*60){
                std::cout << "Arrving task " << tasklist[i].id << ", " << tasklist[i].name << " : " << tasklist[i].detail << ". " << std::endl;
            }

        }


        

        sleep(check_interval);
    }

    return NULL;
   
}