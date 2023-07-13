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
    int check_interval = 5;
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
        //need quit?
        if(thread_arg_ptr->running == false){
            return NULL;
        }
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
            // difft = difftime(tasklist[i].rem, timep);

            if(tasklist[i].rem < timep && timep < tasklist[i].s_time){
                std::cout << "\033[31mArrving task " << tasklist[i].id << ", " << tasklist[i].name << " : " << tasklist[i].detail << ". \033[0m" << std::endl;
            }

        }


        

        sleep(check_interval);
    }

    return NULL;
   
}
