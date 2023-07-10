#ifndef TYPES_H
#define TYPES_H
#include <time.h>
#include<pthread.h>


enum Priority{
    HIGH, MODERATE, LOW
};

enum Category{
    STUDY, LIFE, ENTERTAINMENT
};

typedef struct
{
    int id; 
    char name[32];
    time_t s_time;  //任务启动时间
    Priority prio;  //任务优先级
    Category cat;   //类别
    time_t rem; //reminder, 提醒时间
    char detail[256];   //任务详细信息
}Task;

typedef struct{
    int id; // user_id
    char username[32];
    char password[128]; // hash
}User;

typedef struct{
    User* user;
    pthread_mutex_t* mutex;
    bool running;
}Thread_Arg;

#endif
