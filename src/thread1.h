#ifndef _THREAD1_H
#define _THREAD1_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <pthread.h>
#include <vector>
#include <string.h>
#include <regex>
#include "types.h"
#include "Tasks.h"

void *thread1(void *thread_arg);
void printHelp();
void getCurrent(std::vector<Task> &tasks, std::string currentLine, const User *user);
void saveSingleTask(const Task task, const User *user);
void addTask(std::vector<Task> &tasks, const User *user);
std::string taskToString(Task task);
void delTask(std::vector<Task> tasks, const User *user);
bool checkTime(const string time);

#endif