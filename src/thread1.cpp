#include "thread1.h"
#include "types.h"
#include "Tasks.h"
using namespace std;

void *thread1(void *thread_arg)
{
    string command;
    string clear = "\n";
    getline(cin, command); // 清空缓冲区

    bool stop = false;

    while (!stop)
    {

        vector<Task> tasks;
        // 加载任务
        pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
        loadTask(tasks, ((Thread_Arg *)thread_arg)->user);
        pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);

        // getline(cin, command);
        getline(cin, command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "run") // 开始轮询
        {
            cout << "-----------------------------------------------" << endl;
            cout << "Please input commands!\n";
            while (1)
            {
                // 需要重新加载任务
                // pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                // loadTask(tasks, ((Thread_Arg *)thread_arg)->user);
                // pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);

                // getline(cin, clear);
                getline(cin, command);
                // cout << command << "hh" << endl;
                transform(command.begin(), command.end(), command.begin(), ::tolower);
                if (command == "addtask")
                {
                    bool over = false;
                    string overStr;

                    while (!over)
                    {
                        cout << "Please input task info:" << endl;
                        cout << "Format as below:" << endl;
                        cout << "Task Name,Remind Time(YYYY-MM-DD HH:MM:SS),Priority(low,mederate,high),Category(study,life,entermaint),Remind Time(YYYY-MM-DD HH:MM:SS),Details" << endl;

                        pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);

                        // loadTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        addTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        // showTask(tasks);
                        // saveTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);
                        cout << "Add task complete!" << endl;
                        cout << "-----------------------------------------------" << endl;

                        cout << "Continue add task? (\"n\" to stop)" << endl;
                        getline(cin, overStr);
                        if (overStr == "n")
                        {
                            over = true;
                            cout << "Quit add task" << endl;
                            cout << "-----------------------------------------------" << endl;
                        }
                    }

                    continue;
                }
                if (command == "showtask")
                {
                    // 按开始时间排序   ID重复的不会输出
                    pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                    showTask(tasks);
                    pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);

                    cout << "-----------------------------------------------" << endl;

                    continue;
                }
                if (command == "searchtask")
                {
                    pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                    searchTask(tasks);
                    pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);

                    cout << "-----------------------------------------------" << endl;

                    continue;
                }
                if (command == "deltask")
                {
                    bool over = false;
                    string overStr;

                    while (!over)
                    {
                        cout << "Please input task id:" << endl;

                        pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                        // loadTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        delTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        // saveTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);
                        cout << "-----------------------------------------------" << endl;

                        cout << "Continue delete task? (\"n\" to stop)" << endl;
                        getline(cin, overStr);
                        if (overStr == "n")
                        {
                            over = true;
                            cout << "Quit delete task" << endl;
                            cout << "-----------------------------------------------" << endl;
                        }
                    }
                    continue;
                }
                if (command == "savetask")
                {
                    pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                    saveTask(tasks, ((Thread_Arg *)thread_arg)->user);
                    pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);
                    cout << "-----------------------------------------------" << endl;

                    continue;
                }
                if (command == "help")
                {
                    printHelp();
                    continue;
                }
                if (command == "quit")
                {
                    stop = true;
                    cout << "User:" << ((Thread_Arg *)thread_arg)->user->username << " Quit!" << endl;
                    ((Thread_Arg *)thread_arg)->running = false;
                    break;
                }
                else
                {
                    cout << "ERROR: Command \"" << command << "\" not found! Please check again!" << endl;
                    printHelp();
                    continue;
                }
            }
        }
        else if (command != "run")
        {
            cout << "Unknown command \"" << command << "\"! Type \"run\" to start input shcedules!\n";
            printHelp();
        }
    }
    return NULL;
}

void printHelp()
{
    cout << "Usage: [options]\n";
    cout << "Options:\n";
    cout << "    run         Begin polling user tasks\n";
    cout << "When polling begin:\n";
    cout << "    addTask     Add tasks\n";
    cout << "    showTask    Show all task (earliest start time comes first)\n";
    cout << "    delTask     Delete tasks\n";
    cout << "    saveTask    Save tasks to local file\n";
    cout << "    searchTask  Search tasks with same feature\n";
    cout << "    help        Show this help message\n";
    cout << "    quit        Current user quit\n";
    cout << "-----------------------------------------------" << endl;
}

bool checkTime(const string time)
{
    // 合法为true
    // 正则表达式模式
    string pattern = R"(^\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}$)";

    // 创建正则表达式对象
    regex regex(pattern);

    // 使用正则表达式匹配字符串
    return regex_match(time, regex);
}

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

void getCurrent(vector<Task> &tasks, string currentLine, const User *user)
{
    istringstream iss(currentLine);
    string name, sTimeStr, prioStr, catStr, remStr, detail; // id, s_time自动生成
    Task task;
    bool NoError = false;

    // id
    int id = getminId(tasks);

    // name
    if (getline(iss >> ws, name, ','))
    {
        if (name == "")
            name = "Default Name";

        // s_time
        time_t s_time;
        if (getline(iss >> ws, sTimeStr, ','))
        {
            if (!checkTime(sTimeStr))
            {
                cout << "Invalid start time! Please input with the format: YYYY-MM-DD HH:MM:SS" << endl;
                return;
            }
            else
                s_time = convertToTime(sTimeStr);

            // prio
            Priority prio;
            if (getline(iss >> ws, prioStr, ','))
            {
                prio = convertToPriority(prioStr);

                // category
                Category cat;
                if (getline(iss >> ws, catStr, ','))
                {
                    cat = convertToCategory(catStr);

                    // rem
                    time_t rem;
                    if (getline(iss >> ws, remStr, ','))
                    {
                        if (remStr == "")
                            rem = s_time;
                        else if (!checkTime(remStr))
                        {
                            cout << "Invalid remind time! Please input with the format: YYYY-MM-DD HH:MM:SS" << endl;
                            return;
                        }
                        else
                            rem = convertToTime(remStr);

                        if (rem > s_time)
                        {
                            cout << "Invalid remind time! Please check again" << endl;
                            cout << "-----------------------------------------------" << endl;

                            return;
                        }

                        // detail
                        if (getline(iss >> ws, detail))
                        {
                            if (detail == "\n" || detail == "")
                                detail = "Default";
                        }
                        else
                            detail = "Default";

                        // new_task
                        // Task task;
                        task.id = id;
                        strncpy(task.name, name.c_str(), sizeof(task.name) - 1);
                        task.s_time = s_time;
                        task.prio = prio;
                        task.cat = cat;
                        task.rem = rem;

                        strncpy(task.detail, detail.c_str(), sizeof(task.detail) - 1);

                        tasks.push_back(task);

                        saveSingleTask(task, user);

                        NoError = true;
                    }
                }
            }
        }
    }
    if (NoError == false)
        cout << "Invalid Input! Please check again!" << endl;
}

void saveSingleTask(const Task task, const User *user)
{
    string user_name(user->username);
    string filename = USER_DIR + user_name + ".txt";

    ofstream file;
    file.open(filename, ios::app);

    if (!file)
    {
        cout << "Failed to open task file for saving!\n";
        return;
    }

    file << task.id << ","
         << task.name << ","
         << convertTimeToString(task.s_time) << ","
         << convertPriorityToString(task.prio) << ","
         << convertCategoryToString(task.cat) << ","
         << convertTimeToString(task.rem) << ","
         << task.detail << endl;

    file.close();
}

void addTask(vector<Task> &tasks, const User *user)
{
    string currentLine;
    // Task currentTask;
    string clear = "\n";

    // getline(cin, clear);
    getline(cin, currentLine);
    getCurrent(tasks, currentLine, user);
}

string taskToString(Task task)
{
    ostringstream oss;
    oss << task.id << " " << task.name << " " << task.s_time << " " << task.prio << " " << task.cat << " " << task.rem << " " << task.detail;
    return oss.str();
}

void delTask(vector<Task> tasks, const User *user)
{
    // string taskLine;
    // Task currentTask;
    string clear = "\n";
    int currentID;
    cin >> currentID;
    getline(cin, clear); // 清空缓存区

    bool idExists = false;
    for (const Task &task : tasks)
    {
        if (task.id == currentID)
        {
            idExists = true;
            break;
        }
    }

    if (!idExists)
    {
        cout << "ERROR: Task with ID " << currentID << " does not exist! Please check again." << endl;
        return;
    }

    // 同id的都删了
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [currentID](const Task &task)
                          { return task.id == currentID; }),
                tasks.end());

    // 更新文件
    // 重新写入
    saveTask(tasks, user);
    cout << "Delete task complete!" << endl;
}

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
        cout << "Please input the priority you want to search: (HIGH, MODERATE, LOW)\n";
        string prioStr;
        getline(cin, prioStr);
        transform(prioStr.begin(), prioStr.end(), prioStr.begin(), ::toupper);

        searchTaskPrio(tasks, prioStr);
        break;
    }

    case 2:
    {
        cout << "Please input the category you want to search: (STUDY, LIFE, ENTERTAINMENT)\n";
        string catStr;
        getline(cin, catStr);
        transform(catStr.begin(), catStr.end(), catStr.begin(), ::toupper);

        searchTaskCat(tasks, catStr);
        break;
    }
    case 3:
    {
        cout << "Please input the date(YYYY-MM-DD) you want to search:\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkDay(dateStr))
        {
            cout << "Invalid date! Please input with the format: YYYY-MM-DD HH:MM:SS" << endl;
            return;
        }

        searchTaskDay(tasks, dateStr);
        break;
    }
    case 4:
    {
        cout << "Please input the month(YYYY-MM) you want to search:\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkMonth(dateStr))
        {
            cout << "Invalid date! Please input with the format: YYYY-MM-DD HH:MM:SS" << endl;
            return;
        }

        searchTaskMonth(tasks, dateStr);
        break;
    }
    case 5:
    {
        cout << "Please input the year(YYYY) you want to search:\n";
        string dateStr;
        getline(cin, dateStr);

        if (!checkYear(dateStr))
        {
            cout << "Invalid date! Please input with the format: YYYY-MM-DD HH:MM:SS" << endl;
            return;
        }

        searchTaskYear(tasks, dateStr);
        break;
    }
    default:
    {
        cout << "Unknown type! Please check again!\n";
    }
    }

    // cout << "Search task complete!\n";
}

void showSingleTask(const Task &task)
{
    printf("%2d\t%-12s%-24s%-12s%-16s%-24s%s\n", task.id, task.name, convertTimeToString(task.s_time).c_str(),
           convertPriorityToString(task.prio).c_str(), convertCategoryToString(task.cat).c_str(),
           convertTimeToString(task.rem).c_str(), task.detail);
}

void searchTaskPrio(const vector<Task> &tasks, const string prioStr)
{
    Priority prio = convertToPriority(prioStr);
    cout << "Tasks with priority " << prioStr << ":" << endl;
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
    cout << "Tasks with category " << catStr << ":" << endl;
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
    cout << "Tasks with date " << dateStr << ":" << endl;
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
    cout << "Tasks with month " << dateStr << ":" << endl;
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
    cout << "Tasks with year " << dateStr << ":" << endl;
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
    cout << "Please choose the type of task showing:" << endl;
    cout << "1:\tSearch tasks with the same Priority (Default: LOW)\n";
    cout << "2:\tSearch tasks with the same Category (Default: STUDY)\n";
    cout << "3:\tSearch tasks that start at the same day\n";
    cout << "4:\tSearch tasks that start at the same month\n";
    cout << "5:\tSearch tasks that start at the same year\n";
    cout << "-----------------------------------------------" << endl;
}