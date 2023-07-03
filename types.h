#include<time.h>

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
    struct tm s_time;  //任务启动时间
    Priority prio;  //任务优先级
    Category cat;   //类别
    struct tm rem; //reminder, 提醒时间
    char detail[256];   //任务详细信息
}Task;

typedef struct{
    int id; // user_id
    char username[32];
    char password[128]; // hash
}User;
