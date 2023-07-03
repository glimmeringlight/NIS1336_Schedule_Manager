#include "Account.h"

using namespace std;

extern const string USER_DIR;

Account::Account(const string& filename)
{
    this->filename = filename;

    ifstream file(filename);
    if (!file)  ofstream newFile(filename);
    
}


Account::~Account()
{
}


string hashString(const string& input)
{
    hash<string> hasher;
    size_t hashValue = hasher(input);

    // 将哈希值转换为字符串表示
    stringstream ss;
    ss << hex << hashValue;
    string hashedString = ss.str();

    return hashedString;
}


bool isUsernameExists(const string& username, const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        printf("Account file cannot open!\n");
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string id, name, password;

        if (getline(iss, id, '.') && getline(iss, name, ',') && getline(iss, password)) {
            if (name == username) {
                file.close();
                return true; // 用户名已存在
            }
        }
    }

    file.close();
    return false;
}


int countUser(const string& filename) {
    ifstream file(filename);
    if (!file) {
        printf("File cannot open!\n");
        return 0;
    }


    int Count = 0;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            Count++;
        }
    }

    file.close();
    return Count;
}


int isValid(const string& username, const string& password, const string& filename) {
    ifstream file(filename);
    if (!file) {
        // should not happen
        printf("Account file cannot open!\n");
        return 0;
    }

    string line;
    while (getline(file, line)) {

        istringstream iss(line);
        string id, name, storedPassword;

        if (getline(iss, id, '.') && getline(iss, name, ',') && getline(iss, storedPassword)) {
            // printf("%s %s %s\n", id.c_str(), name.c_str(), storedPassword.c_str());
            if (name == username && storedPassword == password) {
                return stoi(id); 
            }
        }
    }

    file.close();
    return 0; 
}


bool Account::registerUser(const char* input_username, const char* input_pwd)
{
    
    string username(input_username);
    string password(input_pwd);

    if(isUsernameExists(username, filename)) 
    {
        printf("User %s already exists! Please change your username.\n",input_username);
        return false;
    }

    int user_number = countUser(filename);
    string id = to_string(user_number+1);

    // open
    FILE* file = fopen(filename.c_str(), "a");
    if (!file)
    {
        // should not happen
        printf("Account file cannot open!\n");
        return false;
    }

    // hash
    string hashpwd = hashString(password);

    // write in
    string line = id + "." + username + "," + hashpwd + "\n";
    fwrite(line.c_str(), sizeof(char), line.length(), file);

    // close
    fclose(file);


    string user_file = USER_DIR + username + ".txt";
    ofstream ufile(user_file);

    printf("Registration successful!\n");


    return true;
}


int Account::login(const char* input_username, const char* input_pwd)
{

    string username(input_username);
    string password(input_pwd);

    // hash
    string hashpwd = hashString(password);

    // verify
    User user;
    int userid;
    userid = isValid(username, hashpwd, filename );
    if ( userid ) {
        printf("Login successful!\n");
        return userid;
    } else {
        printf("Incorrect user name or password. Please check your input.\n");
        return 0;
    }

}
