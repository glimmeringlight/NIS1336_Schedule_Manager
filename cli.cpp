#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<vector>
#include<string.h>
#include<sstream>
#include<iomanip>
#include "Tasks.h"

void showTask(int argc, char * argv[]);
void addTask(int argc, char * argv[]);
void delTask(int argc, char * argv[]);
void cmdError();
void showUsage();

int main(int argc, char * argv[]){
    /*
    support commands:
    ./cli show -u username -p password 
    ./cli add -u username -p password -n name -p prio -c cat -r rem -d detail -s start
    ./cli del -u username -p password -i id
    */

    int op = 0;
    if(!strncmp(argv[1], "show", 4)) op = 1;
    if(!strncmp(argv[1], "add", 3)) op = 2;
    if(!strncmp(argv[1], "del", 3)) op = 3;
    if(!strncmp(argv[1], "help", 4)) op = 4;

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

    char* prio = NULL;
    char* cat = NULL;
    strcpy(prio, "LOW");
    strcpy(cat, "LIFE");
    
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
        }
    }

    if(flag){
        saveTask(tasklist, &user);
        printf("Delete successfully!\n");
    }else{
        printf("Cannot find this task.\n");
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
}