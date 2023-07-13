#include "thread1.h"
#include "types.h"
#include "Tasks.h"
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

bool checkDay(const string time)
{
    // 合法为true
    string pattern = R"(^\d{4}-\d{2}-\d{2}$)";
    regex regex(pattern);
    return regex_match(time, regex);
}

bool checkMonth(const string time)
{
    // 合法为true
    string pattern = R"(^\d{4}-\d{2}$)";
    regex regex(pattern);
    return regex_match(time, regex);
}

bool checkYear(const string time)
{
    // 合法为true
    string pattern = R"(^\d{4}$)";
    regex regex(pattern);
    return regex_match(time, regex);
}

void searchTaskPrio(const vector<Task> &tasks, const string prioStr)
{
    Priority prio = convertToPriority(prioStr);
    cout << "\033[32mTasks with priority " << prioStr << ":\033[0m" << endl;
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");
    bool noMatch = true;

    for (const Task &task : tasks)
    {
        if (task.prio == prio)
        {
            showSingleTask(task);
            noMatch = false;
        }
    }

    if (noMatch)
    {
        cout << "Tasks with priority " << prioStr << " not found!" << endl;
    }
}

void searchTaskCat(const vector<Task> &tasks, const string catStr)
{
    Category cat = convertToCategory(catStr);
    cout << "\033[32mTasks with category " << catStr << ":\033[0m" << endl;
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");
    bool noMatch = true;

    for (const Task &task : tasks)
    {
        if (task.cat == cat)
        {
            showSingleTask(task);
            noMatch = false;
        }
    }

    if (noMatch)
    {
        cout << "Tasks with category " << catStr << " not found!" << endl;
    }
}

void searchTaskDay(const vector<Task> &tasks, const string dateStr)
{
    cout << "\033[32mTasks with date " << dateStr << ":\033[0m" << endl;
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");
    bool noMatch = true;

    for (const Task &task : tasks)
    {
        string currentDate = convertTimeToString(task.s_time).substr(0, 10);
        if (currentDate == dateStr)
        {
            showSingleTask(task);
            noMatch = false;
        }
    }

    if (noMatch)
    {
        cout << "Tasks with date " << dateStr << " not found!" << endl;
    }
}

void searchTaskMonth(const vector<Task> &tasks, const string dateStr)
{
    cout << "\033[32mTasks with month " << dateStr << ":\033[0m" << endl;
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");
    bool noMatch = true;

    for (const Task &task : tasks)
    {
        string currentDate = convertTimeToString(task.s_time).substr(0, 7);
        if (currentDate == dateStr)
        {
            showSingleTask(task);
            noMatch = false;
        }
    }

    if (noMatch)
    {
        cout << "Tasks with month " << dateStr << " not found!" << endl;
    }
}

void searchTaskYear(const vector<Task> &tasks, const string dateStr)
{
    cout << "\033[32mTasks with year " << dateStr << ":\033[0m" << endl;
    printf("%2s\t%-12s%-24s%-12s%-16s%-24s%s\n", "ID", "Task Name", "Start Time", "Priority", "Category", "Remind Time", "Details");
    bool noMatch = true;

    for (const Task &task : tasks)
    {
        string currentDate = convertTimeToString(task.s_time).substr(0, 4);
        if (currentDate == dateStr)
        {
            showSingleTask(task);
            noMatch = false;
        }
    }

    if (noMatch)
    {
        cout << "Tasks with year " << dateStr << " not found!" << endl;
    }
}

void searchTaskHelp()
{
    cout << "\033[32mPlease choose the type of task showing:\033[0m" << endl;
    cout << "1:\tSearch tasks with the same Priority (Default: LOW)\n";
    cout << "2:\tSearch tasks with the same Category (Default: STUDY)\n";
    cout << "3:\tSearch tasks that start at the same day\n";
    cout << "4:\tSearch tasks that start at the same month\n";
    cout << "5:\tSearch tasks that start at the same year\n";
    cout << "-----------------------------------------------" << endl;
}

void fixDayUpper(string &dayStr)
{
    // convertStrToTime
    tm timeInfo = {};
    istringstream iss(dayStr);
    iss >> get_time(&timeInfo, "%Y-%m-%d");
    time_t time = mktime(&timeInfo);

    // convertTimeToStr
    stringstream ss;
    struct tm *timeinfo;
    timeinfo = localtime(&time);

    ss << put_time(timeinfo, "%Y-%m-%d");
    dayStr = ss.str();
}

// string convertTimeToString(time_t time)
// {
//     stringstream ss;
//     struct tm *timeinfo;
//     timeinfo = localtime(&time);

//     ss << put_time(timeinfo, "%Y-%m-%d %H:%M:%S");

//     return ss.str();
// }

// time_t convertToTime(const string &timeStr)
// {
//     // timeStr:YYYY-MM-DD HH:MM:SS
//     tm timeInfo = {};
//     istringstream iss(timeStr);
//     iss >> get_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
//     return mktime(&timeInfo);
// }

void searchTask(const vector<Task> &tasks)
{
    searchTaskHelp();
    int type;
    cin >> type;
    cin.get();

    switch (type)
    {
    case 1:
    {
        cout << "\033[32mPlease input the priority you want to search: (HIGH, MODERATE, LOW)\033[0m\n";
        string prioStr;
        getline(cin, prioStr);
        transform(prioStr.begin(), prioStr.end(), prioStr.begin(), ::toupper);

        searchTaskPrio(tasks, prioStr);
        break;
    }

    case 2:
    {
        cout << "\033[32mPlease input the category you want to search: (STUDY, LIFE, ENTERTAINMENT)\033[0m\n";
        string catStr;
        getline(cin, catStr);
        transform(catStr.begin(), catStr.end(), catStr.begin(), ::toupper);

        searchTaskCat(tasks, catStr);
        break;
    }
    case 3:
    {
        cout << "\033[32mPlease input the date(YYYY-MM-DD) you want to search:\033[0m\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkDay(dateStr))
        {
            cout << "\033[41mInvalid date! Please input with the format: YYYY-MM-DD HH:MM:SS\033[0m" << endl;
            return;
        }

        searchTaskDay(tasks, dateStr);
        break;
    }
    case 4:
    {
        cout << "\033[32mPlease input the month(YYYY-MM) you want to search:\033[0m\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkMonth(dateStr))
        {
            cout << "\033[41mInvalid date! Please input with the format: YYYY-MM-DD HH:MM:SS\033[0m" << endl;
            return;
        }

        searchTaskMonth(tasks, dateStr);
        break;
    }
    case 5:
    {
        cout << "\033[32mPlease input the year(YYYY) you want to search:\033[0m\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkYear(dateStr))
        {
            cout << "\033[41mInvalid date! Please input with the format: YYYY-MM-DD HH:MM:SS\033[0m" << endl;
            return;
        }

        searchTaskYear(tasks, dateStr);
        break;
    }
    default:
    {
        cout << "\033[41mUnknown type! Please check again!\033[0m\n";
    }
    }

    // cout << "Search task complete!\n";
}