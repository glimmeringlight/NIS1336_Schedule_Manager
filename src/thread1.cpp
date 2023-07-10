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
                    ((Thread_Arg *)thread_arg)->running = true;
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
    cout << "    addTask     show all info with the sort of id (smallest id comes first)\n";
    cout << "    showTask    show the info of the student with the highest socre\n";
    cout << "    delTask     show average score\n";
    cout << "    help        Show this help message\n";
    cout << "-----------------------------------------------" << endl;
}

void getCurrent(vector<Task> &tasks, string currentLine, const User *user)
{
    istringstream iss(currentLine);
    string name, sTimeStr, prioStr, catStr, remStr, detail; // id, s_time自动生成
    Task task;
    bool error = false;

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
            // if (sTimeStr == "")
            //    s_time = time(NULL);
            // else
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
                        rem = convertToTime(remStr);
                        if (rem >= s_time)
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
                            // cout << detail << endl;

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

                            error = true;
                        }
                    }
                }
            }
        }
    }

    if (error == false)
    {
        cout << "Input Error! Please check again!" << endl;
    }
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
