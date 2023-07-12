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
bool checkDay(const string time);
bool checkMonth(const string time);
bool checkYear(const string time);

void searchTask(const vector<Task> &tasks);
void showSingleTask(const Task &task);
void searchTaskPrio(const vector<Task> &tasks, const string prioStr);
void searchTaskCat(const vector<Task> &tasks, const string catStr);
void searchTaskDay(const vector<Task> &tasks, const string dateStr);
void searchTaskMonth(const vector<Task> &tasks, const string dateStr);
void searchTaskYear(const vector<Task> &tasks, const string dateStr);
void searchTaskHelp();

#endif