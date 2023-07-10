#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<vector>
#include<string.h>
#include<sstream>
#include<iomanip>
#include<unistd.h>
#include<iostream>
#include "Tasks.h"

void showTask(int argc, char * argv[]);
void addTask(int argc, char * argv[]);
void delTask(int argc, char * argv[]);
void userLogin(int argc, char * argv[]);
void userRegister(int argc, char * argv[]);
void changePasswd(int argc, char * argv[]);
void checkTask(int argc, char* argv[]);
void cmdError();
void showUsage();

int main(int argc, char * argv[]){
    /*
    support commands:
    ./cli show -u username -p password 
    ./cli add -u username -p password -n name -p prio -c cat -r rem -d detail -s start
    ./cli del -u username -p password -i id
    ./cli login -u username -p password
    ./cli reg -u username -p password
    ./cli passwd -u username -p password -n newpassword
    ./cli check -u username -p password
    */

    int op = 0;
    if(!strncmp(argv[1], "show", 4)) op = 1;
    if(!strncmp(argv[1], "add", 3)) op = 2;
    if(!strncmp(argv[1], "del", 3)) op = 3;
    if(!strncmp(argv[1], "help", 4)) op = 4;
    if(!strncmp(argv[1], "login", 5)) op = 5;
    if(!strncmp(argv[1], "reg", 3)) op = 6;
    if(!strncmp(argv[1], "passwd", 6)) op = 7;
    if(!strncmp(argv[1], "check", 5)) op = 8;

    switch (op)
    {
    case 1:
        showTask(argc, argv);
        break;

    case 2:
        addTask(argc, argv);
        break;

    case 3:
        delTask(argc, argv);
        break;

    case 4:
        showUsage();
        break;

    case 5:
        userLogin(argc, argv);
        break;

    case 6:
        userRegister(argc, argv);
        break;

    case 7:
        changePasswd(argc, argv);
        break;

    case 8:
        checkTask(argc, argv);
        break;


    default:
        cmdError();
        break;


    }

    return 0;
}

void showTask(int argc, char * argv[]){
    char* username = NULL;
    char* password = NULL;
    Account account("USER_PWD.txt");
    char optret;

    while((optret = getopt(argc, argv, "u:p:")) != -1){
        switch(optret)
        {
        case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        
        }
    }

    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    User user = account.login(username, password);
    if(user.id == 0){
        printf("User auth failed!\n");
        exit(-1);
    }

    std::vector<Task> tasklist;
    loadTask(tasklist, &user);

    showTask(tasklist);

}

void addTask(int argc, char * argv[]){
    /*
    ./cli add -u username -p password -n name -o prio -c cat -r rem -d detail -s start
    */

    Account account("USER_PWD.txt");

    char* username = NULL;
    char* password = NULL;
    char* name = NULL;

    char* prio = (char*)"LOW";
    char* cat = (char*)"LIFE";

    char* rem = NULL;
    char* detail = NULL;
    char* st = NULL;

    char optret;

    while((optret = getopt(argc, argv, "u:p:n:o:c:r:d:s:")) != -1){
        switch (optret)
        {
        case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        case 'n':
            name = optarg;
            break;
        
        case 'o':
            prio = optarg;
            break;

        case 'c':
            cat = optarg;
            break;

        case 'r':
            rem = optarg;
            break;

        case 'd':
            detail = optarg;
            break;

        case 's':
            st = optarg;
            break;

        default:
            break;
        }
    }

    //check auth
    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    User user = account.login(username, password);
    if(user.id == 0){
        printf("User auth failed!\n");
        exit(-1);
    }

    Task new_task;
    std::vector<Task> tasklist;
    loadTask(tasklist, &user);

    new_task.id = getminId(tasklist);

    //processing task name
    if(name == NULL){
        printf("Please input task name!\n");
        exit(-1);
    }

    //check name 
    bool flag = false;
    for(int i=0; i<tasklist.size();++i){
        if(!strcmp(name, tasklist[i].name)){
            flag = true;
            break;
        }
    }
    if(flag){
        printf("This task name is unavailable!\n");
        exit(-1);
    }

    strcpy(new_task.name, name);

    //check prio
    flag = false;
    Priority n_prio;
    if(!strcmp(prio, "LOW")){
        flag = true;
        n_prio = LOW;
    }
    if(!strcmp(prio, "MODERATE")){
        flag = true;
        n_prio = MODERATE;
    }
    if(!strcmp(prio, "HIGH")){
        flag = true;
        n_prio = HIGH;
    }

    if(!flag){
        printf("Unknown priority!\n");
        exit(-1);
    }
    new_task.prio = n_prio;

    //check category
    flag = false;
    Category n_cat;
    if(!strcmp(cat, "STUDY")){
        flag = true;
        n_cat = STUDY;
    }
    if(!strcmp(cat, "LIFE")){
        flag = true;
        n_cat = LIFE;
    }
    if(!strcmp(cat, "ENTERTAINMENT")){
        flag = true;
        n_cat = ENTERTAINMENT;
    }

    if(!flag){
        printf("Unknown category!\n");
        exit(-1);
    }
    new_task.cat = n_cat;

    //check detail
    strcpy(new_task.detail, detail);

    //checktime
    if(rem == NULL || st == NULL){
        printf("Please input time!\n");
        exit(-1);
    }

    std::string r_time_str = rem;
    std::string s_time_str = st;

    tm r_time_tm = {};
    tm s_time_tm = {};

    std::istringstream sr(r_time_str);
    std::istringstream ss(s_time_str);
    sr >> std::get_time(&r_time_tm, "%Y-%m-%d,%T");
    ss >> std::get_time(&s_time_tm, "%Y-%m-%d,%T");

    new_task.rem = mktime(&r_time_tm);
    new_task.s_time = mktime(&s_time_tm);

    time_t current_time;
    time(&current_time);
    if(current_time > new_task.rem || current_time > new_task.s_time){
        printf("Invalid time.\n");
        exit(-1);
    }

    if(new_task.rem > new_task.s_time){
        printf("Remind time cannot be earlier than start time.\n");
        exit(-1);
    }

    //add new elements
    tasklist.push_back(new_task);

    saveTask(tasklist, &user);





}

void delTask(int argc, char * argv[]){
    char* username = NULL;
    char* password = NULL;
    int id;
    char optret;

    Account account("USER_PWD.txt");

    while((optret = getopt(argc, argv, "u:p:i:")) != -1){
        switch(optret){
        case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        case 'i':
            id = atoi(optarg);
            break;

        default:
            break;
        }
    }

    //check user auth
    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    User user = account.login(username, password);

    if(user.id == 0){
        printf("User auth failed.\n");
        exit(-1);
    }

    std::vector<Task> tasklist;
    loadTask(tasklist, &user);
    bool flag = false;

    for(auto it = tasklist.begin(); it != tasklist.end(); ++it){
        if((*it).id == id){
            tasklist.erase(it);
            flag = true;
            break;  //if deleted, exit loop
        }
    }

    if(flag){
        saveTask(tasklist, &user);
        printf("Delete successfully!\n");
    }else{
        printf("Cannot find this task.\n");
    }
    
}

void userLogin(int argc, char* argv[]){
    char* username = NULL;
    char* password = NULL;
    Account account("USER_PWD.txt");

    char optret;
    while((optret = getopt(argc,argv,"u:p:"))!=-1){
        switch(optret){
            case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        default:
            break;
        }
    }

    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    User user = account.login(username, password);

    if(user.id == 0){
        printf("User auth failed!\n");
        exit(-1);
    }else{
        printf("Successfully loged in as %s.\n", user.username);
    }
}

void userRegister(int argc, char* argv[]){
    char* username = NULL;
    char* password = NULL;
    Account account("USER_PWD.txt");

    char optret;
    while((optret = getopt(argc,argv,"u:p:"))!=-1){
        switch(optret){
            case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        default:
            break;
        }
    }

    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    bool flag = account.registerUser(username, password);
    if(flag){
        printf("Registration succeeded!\n");
    }else{
        printf("Registration failed!\n");
        exit(-1);
    }
}

void changePasswd(int argc, char* argv[]){
    char* username = NULL;
    char* password = NULL;
    char* new_password = NULL;
    Account account("USER_PWD.txt");

    char optret;
    while((optret = getopt(argc,argv,"u:p:n:"))!=-1){
        switch(optret){
            case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        case 'n':
            new_password = optarg;
            break;

        default:
            break;
        }
    }

    if(username == NULL || password == NULL || new_password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    bool flag = account.changePassword(username, password, new_password);

    if(flag){
        printf("Changed password successfully!\n");
    }else{
        printf("Change password failed!\n");
        exit(-1);
    }
}

void checkTask(int argc, char* argv[]){
    char* username = NULL;
    char* password = NULL;
    Account account("USER_PWD.txt");

    char optret;
    while((optret = getopt(argc,argv,"u:p:"))!=-1){
        switch(optret){
            case 'u':
            username = optarg;
            break;

        case 'p':
            password = optarg;
            break;

        default:
            break;
        }
    }

    if(username == NULL || password == NULL){
        printf("Too few arguments!\n");
        exit(-1);
    }

    User user = account.login(username, password);

    if(user.id == 0){
        printf("User auth failed!\n");
        exit(-1);
    }

    //check task begin
    std::vector<Task> tasklist;
    struct tm *current_time;
    struct tm *task_time;
    double difft = 0;

    loadTask(tasklist, &user);

    //get current time
    time_t timep;
    time(&timep);
    current_time = localtime(&timep);

    //check arriving tasks
    for(int i = 0; i<tasklist.size(); ++i){
            
        task_time = localtime(&(tasklist[i].rem));
            
        if(task_time->tm_year != current_time->tm_year) continue;
        if(task_time->tm_mon != current_time->tm_mon) continue;
        if(task_time->tm_mday != current_time->tm_mday) continue;
        // day match if here
        difft = difftime(tasklist[i].rem, timep);

        if(difft > 0 && difft < 5*60){
            printf("Task %d %s is arriving: %s.\n", 
            tasklist[i].id, tasklist[i].name, tasklist[i].detail);
        }

    }

}

void cmdError(){
    printf("Unknown command! Use help to show usage!\n");
}

void showUsage(){
    printf("Supported commands:\n");
    printf("./cli show -u username -p password\n");
    printf("./cli add -u username -p password -n name -p prio -c cat -r rem -d detail -s start\n");
    printf("./cli del -u username -p password -i id\n");
    printf("./cli login -u username -p password\n");
    printf("./cli reg -u username -p password\n");
    printf("./cli passwd -u username -p password -n newpassword\n");
    printf("./cli check -u username -p password.\n");
    
    
    
}