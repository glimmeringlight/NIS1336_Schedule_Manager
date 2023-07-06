#include "Tasks.h"
#include<time.h>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<algorithm>


Priority convertToPriority(const string& priorityStr) {
    if (priorityStr == "HIGH") {
        return HIGH;
    } else if (priorityStr == "MODERATE") {
        return MODERATE;
    } else if (priorityStr == "LOW") {
        return LOW;
    } else {
        // default
        return LOW;
    }
}


Category convertToCategory(const string& categoryStr) {
    if (categoryStr == "STUDY") {
        return STUDY;
    } else if (categoryStr == "LIFE") {
        return LIFE;
    } else if (categoryStr == "ENTERTAINMENT") {
        return ENTERTAINMENT;
    } else {
        // default
        return STUDY;
    }
}


time_t convertToTime(const string& timeStr) {
    // timeStr:YYYY-MM-DD HH:MM:SS
    tm timeInfo = {};
    istringstream iss(timeStr);
    iss >> get_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
    return mktime(&timeInfo);
}


string convertPriorityToString(Priority priority) {
    switch (priority) {
        case HIGH:
            return "HIGH";
        case MODERATE:
            return "MODERATE";
        case LOW:
            return "LOW";
        default:
            return "LOW";
    }
}


string convertCategoryToString(Category category) {
    switch (category) {
        case STUDY:
            return "STUDY";
        case LIFE:
            return "LIFE";
        case ENTERTAINMENT:
            return "ENTERTAINMENT";
        default:
            return "NONE";
    }
}


string convertTimeToString(time_t time) {
    stringstream ss;
    struct tm* timeinfo;
    timeinfo = localtime(&time);

    ss << put_time(timeinfo, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}


void loadTask(vector<Task>& tasks, const User* user){

    tasks.clear(); 

    string user_name(user->username);
    string filename = "./" + USER_DIR + user_name + ".txt" ;

    ifstream file(filename);
    if (!file) {
        // should not happen
        printf("Failed to open task file!\n");
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string idStr, name, sTimeStr, prioStr, catStr, remStr, detail;
        
        if (getline(iss, idStr, ','))
        {
            // id
            int id = stoi(idStr);
            // name
            if (getline(iss >> ws, name, ','))
            {
                // s_time
                if (getline(iss >> ws, sTimeStr, ','))
                {
                    time_t s_time = convertToTime(sTimeStr);

                    // prio
                    if (getline(iss >> ws, prioStr, ','))
                    {
                        Priority prio = convertToPriority(prioStr);

                        // category
                        if (getline(iss >> ws, catStr, ','))
                        {
                            Category cat = convertToCategory(catStr);

                            // rem
                            if (getline(iss >> ws, remStr, ','))
                            {
                                time_t rem = convertToTime(remStr);

                                // detail
                                if (getline(iss >> ws, detail))
                                {
                                    // new_task
                                    Task task;
                                    task.id = id;
                                    strncpy(task.name, name.c_str(), sizeof(task.name) - 1);
                                    task.s_time = s_time;
                                    task.prio = prio;
                                    task.cat = cat;
                                    task.rem = rem;
                                    strncpy(task.detail, detail.c_str(), sizeof(task.detail) - 1);

                                    tasks.push_back(task);
                                }
                            }
                        }
                    }
                }
            }
        }

    }

    file.close();

}


void saveTask(const vector<Task>& tasks, const User* user){

    string user_name(user->username);
    string filename = USER_DIR + user_name + ".txt" ;

    ofstream file(filename);
    if (!file) {
        printf("Failed to open task file for saving!\n");
        return;
    }

    for (const Task& task : tasks) {
        file << task.id << ","
             << task.name << ","
             << convertTimeToString(task.s_time) << ","
             << convertPriorityToString(task.prio) << ","
             << convertCategoryToString(task.cat) << ","
             << convertTimeToString(task.rem) << ","
             << task.detail << endl;
    }

    file.close();
    printf("Tasks saved successfully.\n");

}


void showTask(const vector<Task>& tasks) {
    vector<Task> newtasks(tasks);

    sort(newtasks.begin(), newtasks.end(), [](const Task& t1, const Task& t2) {
        return t1.s_time < t2.s_time;
    });

    printf("The info of all tasks (most recent start time comes first):\n");
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");

    for (const auto& task : newtasks) {
        printf("%2d\t%-12s%-24s%-12s%-16s%-24s%s\n", task.id, task.name, convertTimeToString(task.s_time).c_str(),
               convertPriorityToString(task.prio).c_str(), convertCategoryToString(task.cat).c_str(),
               convertTimeToString(task.rem).c_str(), task.detail);
    }
}

int getminId(vector<Task> tasks) {
    int size = tasks.size();
    if(size <=0) return 1;
    for(int i=0;i<size;i++){
        while(tasks[i].id>0&&tasks[i].id<size&&(i!=tasks[i].id)){
            int t = tasks[i].id;
            if(tasks[t].id==tasks[i].id) break;
            int tmp = tasks[i].id;
            tasks[i].id=tasks[t].id;
            tasks[t].id = tmp;
        }
    }
    for(int i =1;i<size;i++){
        if(i!=tasks[i].id)return i;
    }

    return size+(tasks[0].id==(size));
}