#ifndef TASKS_H
#define TASKS_H

#include <vector>
#include <string>
#include <ctime>
#include "types.h"
#include "Account.h"

using namespace std;

extern const string USER_DIR;


void showTask(const vector<Task>& tasks);
void loadTask(vector<Task>& tasks, const User* user);
void saveTask(const vector<Task>& tasks, const User* user);


Priority convertToPriority(const string& priorityStr);
Category convertToCategory(const string& categoryStr);
time_t convertToTime(const string& timeStr);

string convertPriorityToString(Priority priority);
string convertCategoryToString(Category category);
string convertTimeToString(time_t time);


#endif
