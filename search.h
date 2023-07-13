#ifndef _SEARCH_H
#define _SEARCH_H

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

bool checkDay(const string time);
bool checkMonth(const string time);
bool checkYear(const string time);

void fixDayUpper(string &dayStr);

void searchTask(const vector<Task> &tasks);
void searchTaskPrio(const vector<Task> &tasks, const string prioStr);
void searchTaskCat(const vector<Task> &tasks, const string catStr);
void searchTaskDay(const vector<Task> &tasks, const string dateStr);
void searchTaskMonth(const vector<Task> &tasks, const string dateStr);
void searchTaskYear(const vector<Task> &tasks, const string dateStr);
void searchTaskHelp();

#endif