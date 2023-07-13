#include "thread1.h"
#include "types.h"
#include "Tasks.h"
#include "search.h"
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
            cout << "\033[32mPlease input commands!\033[0m\n";
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
                        cout << "\033[32mPlease input task info:\033[0m" << endl;
                        cout << "\033[32mFormat as below:\033[0m" << endl;
                        cout << "\033[32mTask Name,Start Time(YYYY-MM-DD HH:MM:SS),Priority(low,mederate,high),Category(study,life,entermaint),Remind Time(YYYY-MM-DD HH:MM:SS),Details\033[0m" << endl;

                        pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);

                        // loadTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        addTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        // showTask(tasks);
                        // saveTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);
                        cout << "\033[42mAdd task complete!\033[0m" << endl;
                        cout << "-----------------------------------------------" << endl;

                        cout << "\033[32mContinue add task? (\"n\" to stop)\033[0m" << endl;
                        getline(cin, overStr);
                        if (overStr == "n")
                        {
                            over = true;
                            cout << "\033[42mQuit add task\033[0m" << endl;
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
                        cout << "\033[32mPlease input task id:\033[0m" << endl;

                        pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                        // loadTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        delTask(tasks, ((Thread_Arg *)thread_arg)->user);
                        // saveTask(tasks, ((Thread_Arg *)thread_arg)->user);

                        pthread_mutex_unlock(((Thread_Arg *)thread_arg)->mutex);
                        cout << "-----------------------------------------------" << endl;

                        cout << "\033[32mContinue delete task? (\"n\" to stop)\033[0m" << endl;
                        getline(cin, overStr);
                        if (overStr == "n")
                        {
                            over = true;
                            cout << "\033[42mQuit delete task\033[0m" << endl;
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
                if (command == "edittask")
                {
                    pthread_mutex_lock(((Thread_Arg *)thread_arg)->mutex);
                    editTask(tasks, ((Thread_Arg *)thread_arg)->user);
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
                    cout << "\033[32mUser:" << ((Thread_Arg *)thread_arg)->user->username << " Quit!\033[0m" << endl;
                    ((Thread_Arg *)thread_arg)->running = false;
                    break;
                }
                else
                {
                    cout << "\033[41mERROR: Command \"" << command << "\" not found! Please check again!\033[0m" << endl;
                    printHelp();
                    continue;
                }
            }
        }
        else if (command != "run")
        {
            cout << "\033[41mUnknown command \"" << command << "\"! Type \"run\" to start input shcedules!\033[0m\n";
            printHelp();
        }
    }
    return NULL;
}

void printHelp()
{
    cout << "\033[32mUsage: [options]\033[0m\n";
    cout << "Options:\n";
    cout << "    run         Begin polling user tasks\n";
    cout << "When polling begin:\n";
    cout << "    addTask     Add tasks\n";
    cout << "    showTask    Show all task (earliest start time comes first)\n";
    cout << "    delTask     Delete tasks\n";
    // cout << "    saveTask    Save tasks to local file\n";
    // cout << "    searchTask  Search tasks with same feature\n";
    cout << "    editTask    edit task with sqecified id\n";
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
                cout << "\033[41mInvalid start time! Please input with the format: YYYY-MM-DD HH:MM:SS\033[0m" << endl;
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
                            cout << "\033[41mInvalid remind time! Please input with the format: YYYY-MM-DD HH:MM:SS\033[0m" << endl;
                            return;
                        }
                        else
                            rem = convertToTime(remStr);

                        if (rem > s_time)
                        {
                            cout << "\033[41mInvalid remind time! Please check again\033[0m" << endl;
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
        cout << "\033[41mInvalid Input! Please check again!\033[0m" << endl;
}

void saveSingleTask(const Task task, const User *user)
{
    string user_name(user->username);
    string filename = USER_DIR + user_name + ".txt";

    ofstream file;
    file.open(filename, ios::app);

    if (!file)
    {
        cout << "\033[41mFailed to open task file for saving!\033[0m\n";
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

void delTask(vector<Task> &tasks, const User *user)
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
        cout << "\033[41mERROR: Task with ID " << currentID << " does not exist! Please check again.\033[0m" << endl;
        return;
    }

    // 同id的都删了
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [currentID](const Task &task)
                          { return task.id == currentID; }),
                tasks.end());

    // 更新文件
    // 重新写入
    saveTask(tasks, user);
    cout << "\033[42mDelete task complete!\033[0m" << endl;
}

void showSingleTask(const Task &task)
{
    printf("%2d\t%-12s%-24s%-12s%-16s%-24s%s\n", task.id, task.name, convertTimeToString(task.s_time).c_str(),
           convertPriorityToString(task.prio).c_str(), convertCategoryToString(task.cat).c_str(),
           convertTimeToString(task.rem).c_str(), task.detail);
}

void editTask(vector<Task> &tasks, const User *user)
{
    int id;
    cout << "\033[32mPlease input task id:\033[0m\n";
    cin >> id;
    cin.get();

    string command;

    Task *editTask;
    for (Task &task : tasks)
    {
        if (task.id == id)
        {
            editTask = &task;
            break;
        }
    }

    // task name
    cout << "\033[32mTask Name: " << editTask->name << endl;
    cout << "Change or not? (y to change)   \033[0m";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        strncpy(editTask->name, command.c_str(), sizeof(editTask->name) - 1);
    }

    // start time
    cout << "\033[32mStart Time: " << convertTimeToString(editTask->s_time) << endl;
    cout << "Change or not? (y to change)  \033[0m";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        if (!checkTime(command))
        {
            cout << "\033[31mInvalid start time! Please check again!\033[0m\n";
        }
        else
        {
            time_t s_time = convertToTime(command);
            editTask->s_time = s_time;
        }
    }

    // priority
    cout << "\033[32mPriority: " << convertPriorityToString(editTask->prio) << endl;
    cout << "Change or not? (y to change)   \033[0m";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        Priority prio = convertToPriority(command);
        editTask->prio = prio;
    }

    // category
    cout << "\033[32mCategory: " << convertCategoryToString(editTask->cat) << endl;
    cout << "Change or not? (y to change)   \033[0m";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        Category cat = convertToCategory(command);
        editTask->cat = cat;
    }

    // remind time
    cout << "\033[32mRemind Time: " << convertTimeToString(editTask->rem) << endl;
    cout << "Change or not? (y to change)   \033[0m";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        if (!checkTime(command))
        {
            cout << "\033[31mInvalid remind time! Please check again!\033[0m\n";
        }
        else
        {
            time_t rem = convertToTime(command);
            editTask->rem = rem;
        }
    }

    // details
    cout << "\033[32mDetails: " << editTask->detail << endl;
    cout << "Change or not? (y to change)\033[0m   ";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "y")
    {
        getline(cin, command);
        strncpy(editTask->detail, command.c_str(), sizeof(editTask->detail) - 1);
    }

    // tasks.erase(remove_if(tasks.begin(), tasks.end(), [id](const Task &task)
    //                       { return task.id == id; }),
    //             tasks.end());
    // tasks.push_back(editTask);

    saveTask(tasks, user);
    cout << "\033[32mTask id " << editTask->id << " edit complete!\033[0m\n";
    showSingleTask(*editTask);
}