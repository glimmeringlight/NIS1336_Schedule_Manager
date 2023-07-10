#include"checkTask.h"
#include"types.h"
#include"Account.h"
#include"thread1.h"


int main(){
    int opt;
    char username[32];
    char password[256];
    Account account("USER_PWD.txt");
    User current_user;
    Thread_Arg thread_arg;

    printf("Input 1 to register, 2 to login.\n");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("User register:\n");
        printf("Input your username:");
        scanf("%s", username);
        printf("Input your password:");
        scanf("%s", password);
        if(account.registerUser(username, password)){
            printf("Register successfully!\n");
        }
        //dont break, next user login

    case 2:
        printf("User login:\n");
        printf("Input your username:");
        scanf("%s", username);
        printf("Input your password:");
        scanf("%s", password);
        current_user = account.login(username, password);
        if(current_user.id == 0){
            printf("Username or password is wrong! Login failed!\n");
            exit(-1);
        }

        printf("Login successfully! Welcome %s.\n", current_user.username);
        break;
    
    default:
        printf("Unknown command! Can only accept 1 or 2.\n");
        exit(-1);
        break;
    }



    //互斥锁，用于互斥地访问
	pthread_mutex_t mutex;

    pthread_t tids[2];
    int ret;
    thread_arg.mutex = &mutex;
    thread_arg.user = &current_user;
    thread_arg.running = true;

    ret = pthread_create(&(tids[0]), NULL, thread1, &thread_arg);

    if(ret){
        printf("Create thread failed.\n");
        exit(-1);
    }

    ret = pthread_create(&(tids[1]), NULL, thread2, &thread_arg);
    if(ret){
        printf("Create thread failed.\n");
        exit(-1);
    }

    pthread_exit(NULL);

    return 0;

}
