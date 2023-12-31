# NIS1336_Schedule_Manager

### `Account.cpp`中实现对账号的注册、登录、修改密码的功能

```
Account account("filename.txt");
```

此命令会创建一个`Account`类对象，并在该目录下新建一个文件（如果没有的话）`filename.txt`，用于保存用户名及密码。

示例：

```
Account account(USER_PWD.txt);
```

**1.账号注册**

```
bool registerUser(const char* username, const char* password);
```

注册成功则返回`True`，注册过程中会检查用户名是否已经存在。如果该用户名可用，注册过程中会在`USER`文件夹中新建文件`username.txt`。

示例：

```
registerUser("Alice","12345678");
```

`USER_PWD.txt`中的保存形式：

```
1.Alice,8c5b90a33a04dca5
```






**2.登录**

```
int login(const char* username, const char* password, User* user);
```

返回的`int`值为`USER_PWD.txt`中的用户编号，如果登陆失败返回`0`。`user`中记录了登录成功的用户信息。


**3.修改密码**
```
bool changePassword(const char* username, const char* password, const char* newpassword);
```
若密码修改成功则返回`true`。





### `Tasks.cpp`中实现任务的加载、保存和打印的功能

**1.任务加载**
```
void loadTask(vector<Task>& tasks, const User* user);
```

**2.任务保存**
```
void saveTask(const vector<Task>& tasks, const User* user);
```

注：`s_time`和`rem`在`username.txt`中保存的格式为`YYYY-MM-DD HH:MM:SS`

示例`USER/Alice.txt`：
```
1,Study,2023-07-05 21:47:00,LOW,ENTERTAINMENT,2023-07-05 00:00:00,GO TO Study!
2,Play,2023-07-03 21:47:00,HIGH,ENTERTAINMENT,2023-07-05 00:00:00,GO TO Play!
3,Play,2023-07-04 21:47:00,HIGH,ENTERTAINMENT,2023-07-05 00:00:00,GO TO Play!
4,Run,2023-07-04 23:47:00,HIGH,ENTERTAINMENT,2023-07-05 00:00:00,GO TO Run!
```




**3.任务打印**
```
void showTask(const vector<Task>& tasks);
```

输出示例（按`Start Time`从小到大排序）：
```
ID	Task Name   Start Time              Priority    Category        Remind Time             Details
 2	Play        2023-07-03 21:47:00     HIGH        ENTERTAINMENT   2023-07-05 00:00:00     GO TO Play!
 3	Play        2023-07-04 21:47:00     HIGH        ENTERTAINMENT   2023-07-05 00:00:00     GO TO Play!
 4	Run         2023-07-04 23:47:00     HIGH        ENTERTAINMENT   2023-07-05 00:00:00     GO TO Run!
 1	Study       2023-07-05 21:47:00     LOW         ENTERTAINMENT   2023-07-05 00:00:00     GO TO Study!
```



