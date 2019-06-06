/*
 Unix Programming kgh Mini Shell Script
 Created by kgh(Gwan Hyeon Kim) on 23/05/2019.
 Copyright © 2019 kgh. All rights reserved.
 Github: https://github.com/kgh940525
*/

#define _CRT_SECURE_NO_WARNINGS    // 입력 에러 처리 하기 위한 정의
#include <stdio.h>      // 입출력 라이브러리
#include <stdlib.h>     // 표준 문자열,메모리 라이브러리
#include <string.h>     // 표준 문자열 라이브러리
#include <unistd.h>     // 다양한 상수와 자료형 함수 관련 라이브러리
#include <fcntl.h>      // 파일 입출력 관련 라이브러리
#include <sys/stat.h>   // 시스템 파일들의 정보 라이브러리
#include <sys/types.h>  // 시스템 파일 프로세스 타입 라이브러리
#include <sys/wait.h>   // 시스템 파일 프로세스 wait 정보 라이브러리
#include <time.h>       // 시간 관련 함수 라이브러리
#include <dirent.h>     // 디렉터리 관련 함수 라이브러리
#include <pwd.h>        // 사용자 정보 라이브러리
#include <grp.h>        // Group 관련 라이브러리
#include <errno.h>      // Error 처리 라이브러리
#define MAX 100         // MAX 상수

// History 명령어 저장하기 위한 구조체
typedef struct _HISTORY{
    char log[MAX];
}HISTORY;
pid_t wait(int *statloc); // wait 자식프로세스 정상/비정상 종료 반환값 처리하기 위함.
// 기능1. cd
int mycd(int argc, char *argv[])
{
    // 경로를 담기위한 cwd 변수
    char cwd[MAX];
    // 디렉토리 경로가 지정되지 않은 경우(cd [arg] 인자 지정하지 않은경우 "/"루트 경로로 이동
    if(argc!=2)
    {
        // 작업 디렉터리 루트 경로로 지정 한다.
        if(!chdir("/")){
            // getcwd() NULL 반환아닐 경우 현재 디렉터리 경로 cwd에 저장
            // sizeof(cwd)+1 의 경우 일 경우 - 현재 경로
            // sizeof(cwd)f 의 경우 - 현재경로의 이전경로 ex) cd
            // 변경된 작업 디렉터리를 cwd에 저장한다.
            if(getcwd(cwd,sizeof(cwd)) != NULL){
                puts(cwd);  // 변경된 작업 디렉터리 경로 출력
            }
        }
        return 0;
    }
    // 0이면 chdir(현재 작업 디렉터리 변경) 성공처리
    if(!chdir(argv[1])){
        // getcwd() NULL 반환아닐 경우 현재 디렉터리 경로 cwd에 저장
        // sizeof(cwd)+1 의 경우 일 경우 - 현재 경로
        // sizeof(cwd)f 의 경우 - 현재경로의 이전경로 ex) cd ..)
        if(getcwd(cwd,sizeof(cwd))!=NULL){
            printf("%s",getcwd(cwd,sizeof(cwd)));
            puts(cwd);  // 변경된 디렉터리 경로 출력
        }else{
            perror("getcwd"); // getcwd를 사용 하였을 경우 발생한 오류 처리
        }
    }else{
        // 현재 작업 디렉토리를 변경하는 동안 발생한 발생 처리
        perror("chdir");
    }
    return 0;
}
// 기능2. 현재 로컬경로 반환
char* my_getcwd(char* user_name)
{
    
    char* cwd;  // 경로 저장하기 위한 변수
    char* home_path; // 홈 경로 저장하기 위한 변수
    int str_len;    // 길이를 저장하기 위한 변수
    home_path = (char *)malloc(strlen(user_name) + strlen("/home/")) + 1;   // 홈 경로 malloc 동적 할당(유저 이름+ home)길이 만큼, +1 NULL 사이즈 만큼
    home_path[strlen(user_name) + strlen("/home/")] = '\0'; // home_path에 NULL값 추가
    sprintf(home_path, "/home/%s", user_name);   //배열버퍼에 홈 경로에 /home/user_name을 추가 하여 저장한다.
    cwd = getcwd(NULL, MAX);        // 추가한 MAX상수 만큼의 cwd의 경로를 가져온다.
    
    // 검색된 문자열이 없을 경우 현재 cwd값 반환한다. 초기값 반환
    if(strstr(cwd, home_path) == NULL){
        return cwd;
    }else{ // 검색된 문자열이 있는 경우(경로를 제대로 반환하였을 경우)
        str_len = strlen(home_path);
        cwd[str_len-1] = '~';       // "~"경로 값 추가
        return &cwd[str_len-1];     // ~경로추가하여 반환
    }
}
// 기능3. pwd 현재 경로 반환
int mypwd(){
    char buffer[100];    // 경로저장하기 위한 buffer
    
    //getcwd로 이전경로 NULL이 아닐 경우 이전 경로 반환하여 출력
    if(getcwd(buffer,sizeof(buffer))){
        printf("%s\n",buffer);
    }else{
        perror("getcwd");
    }
    return 0;
}
// 기능4. echo 명령어 인자 반환
void myecho(char ** argc){
    int i = 1;
    // NULL값일 때 까지 인자값 반환
    while (1){
        if (argc[i] == NULL){
            break;
        }
        printf("%s ", argc[i]);
        i++;
    }
    printf("\n");
}
// 기능5. mkdir 디렉터리 생성
int mymkdir(int argc,char *argv[]){
    
    // 인자값의 수가 올바르지 않을경우 에러처리
    if(argc!=2){
        printf("Invalid number of arguments\n");
        return 0;
    }
    // argv[1]에 지정된 디렉터리의 이름으로 생성 및 파일 접근권한 chmod 0775로 생성
    if(!mkdir(argv[1],0775)){
        printf("%s was created\n",argv[1]);
    }else{ // 디렉터리 생성이 실패하였을 경우 에러 출력
        perror("mkdir");
    }
    return 0;
}
// 기능6. mkdir 디렉터리 삭제
int myrmdir(int argc,char *argv[]){
    if(argc!=2){
        printf("Invalid number\n");
        return 0;
    }
    if(!rmdir(argv[1])){
        printf("%s\n",argv[1]);
    }else{
        perror("rmdir");
    }
    return 0;
}
// 기능7. myhelp 프로그램 기능 설명
int myhelp(char ** args){
    printf("\nA kgh_MiniShell implementation of the Unix Shell by Gwan-Hyeon Kim.\n");
    printf("\nCommands implemented: ");
    printf("\n\t- help");
    printf("\n\t- exit");
    printf("\n\t- cd dir");
    printf("\n\t- pwd");
    printf("\n\t- echo [string to echo]");
    printf("\n\t- clear");
    printf("\n\t- ls [-ail] [dir1 dir2 ...]");
    printf("\n\t- cp source target (or) cp file1 [file2 ...] dir");
    printf("\n\t- mv source target (or) mv file1 [file2 ...] dir");
    printf("\n\t- date is not [argv] currently time print");
    printf("\n\t- history my command list print");
    printf("\n\t- mkdir dir1 [dir2 ...]");
    printf("\n\t- rmdir dir1 [dir2 ...]");
    printf("\n\n");
    return 1;
}
// 기능8. history 나의 명령어 리스트 출력
void myhistory(HISTORY *history,int history_cnt){
    for(int i=0; i<history_cnt; i++){
        printf("%d %s\n",i+1,history[i].log);
    }
}

// KGH Mini Shell Program Main Excecute
int main()
{
    // HISTORY STRUCTURE
    HISTORY *history = (HISTORY *)malloc(sizeof(HISTORY)*1024); // histroy 명령어 담기위한 구조체 변수 동적할당
    char getCommand[MAX];       // 명령을 담기위한 변수
    char *tokens[MAX];  // 문자열 토큰을 담기위한 변수
    int cnt;    // 문자 개수 처리(counting variable)
    char *cwd;  // 현재 경로를 받아내기 위한 변수 path
    char host_name[MAX];       // host_name kgh~local
    char user_name[MAX];        // user_name kgh
    int history_cnt=0;      // histroy 명령어 개수 cnt 변수
    getlogin_r(user_name,MAX);   // local 로그인 user_name 얻기 위한 호출
    gethostname(host_name,MAX);  // local 호스트네임 host_name 얻기 위한 호출
    int status;     // 프로세스 상태 확인 하기 위한 변수
    pid_t childPid;     // 자식프로세스 생성하기 위한 변수
    int tf;         // 지정된 mv,cp,date 기능 이외에는 부모,자식 프로세스 생성 및 종료를 막기 위한 tf 변수
    
    char *local_path;       // execl() 실행을 하기위한 local_path를 저장해놓기 위한 변수
    local_path = my_getcwd(user_name);      //명령어 시작전 현재 프로그램 실행 cwd경로를 local_path에 저장
    
    
    // MINI SHELL SCRIPT 프로그램 실행 부분 - 명령어를 계속 받기위한 반복문
    while(1){
        // 실제 리눅스 명령어 처럼 처리 (host_name/local path)$
        do{
            cnt=0;      // 토큰 처리하기 위한 카운팅 변수
            cwd = my_getcwd(user_name);     // 현재 작업경로를 계속해서 출력해주기 위해 cwd에 저장
            fprintf(stdout,"%s@%s:%s$",user_name,host_name,cwd);    // command 라인에서 현재 경로를 출력하면서 입력할 수 있도록 하기 위한 처리
            // 줄바꿈 문자 제거
            fgets(getCommand,sizeof(getCommand)-1,stdin);       //명령어 한줄 입력 받음. "\n"줄바꿈 제거
            getCommand[strlen(getCommand)-1] = '\0';            // 문자열 끝에 '\0\ 추가
            
            tokens[cnt++]=strtok(getCommand," \n"); // argv[1] 인자 추출 하기 위함(Command)
            while((tokens[cnt++] = strtok(NULL," \n"))); //모든 인수를 명령에 추출하여 토큰에 저장
            
        }while(tokens[0] == '\0');      // Enter일 경우 처리 하기 위한 do~while문
        tokens[cnt] = (char *)NULL; // 마지막인자 NULL처리
        tf = 0; // 매번 명령어 마다 지정된 mv,cp,date 기능 이외에는 부모,자식 프로세스 생성 및 종료를 막기 위한 tf 변수처리 하기위한 초기화
        strcpy(history[history_cnt++].log,getCommand);  // 입력된 명령어 history 구조체에 값 복사
        
        // pwd, cd, mkdir, rmdir, echo, help ,clear, exit 명령일 경우 조건 처리
        if(!strcmp(tokens[0],"pwd") || !strcmp(tokens[0],"cd")|| !strcmp(tokens[0],"mkdir") || !strcmp(tokens[0],"rmdir")|| !strcmp(tokens[0],"echo")||
           !strcmp(tokens[0],"help")|| !strcmp(tokens[0],"clear") || !strcmp(tokens[0],"exit") ) {
            
            // history 함수 조건 처리
            if(!strcmp(tokens[0],"history")){
                myhistory(history,history_cnt);     // history 함수 호출
            }
            // pwd 함수 조건 처리
            else if(!strcmp(tokens[0],"pwd")){
                mypwd();    // pwd 함수 호출
            }
            // cd 함수 조건 처리
            else if(!strcmp(tokens[0],"cd")){
                mycd(cnt-1,tokens);     // mycd 함수 호출
            }
            // mkdir 함수 조건 처리
            else if(!strcmp(tokens[0],"mkdir")){
                mymkdir(cnt-1,tokens);  // mkdir 함수 호출
            }
            // rmdir 함수 조건 처리
            else if(!strcmp(tokens[0],"rmdir")){
                myrmdir(cnt-1,tokens);  // rmdir 함수 호출
            }
            // echo 함수 조건 처리
            else if(!strcmp(tokens[0],"echo")){
                myecho(tokens); // echo 함수 호출
            }
            // help 함수 조건 처리
            else if(!strcmp(tokens[0],"help")){
                myhelp(tokens); // help 함수 호출
            }
            // clear 함수 조건 처리
            else if(!strcmp(tokens[0], "clear")){ //$clear 명령으로 인자가 들어온 경우
                system("clear");    // system call "clear" 함수 호출
            }
            // exit 함수 조건 처리
            else if(!strcmp(tokens[0],"exit")){ // $exit 명령으로 인자가 들어온 경우
                exit(0); // 해당 myShell 프로그램 시스템 종료
            }
            tf = 1;         // 직접 구현한 기능을 처리 했을 경우 다음 조건을 처리하지 않기 위한 설정
        }
        // execl mv,cp,date 함수 실행,이외에 execvp 내장명령어 실행 처리
        else if(tf ==0 ){
            
            // fork() 성공 시 : 부모 프로세스에서는 자식 프로세스의 PID값을 반환 받음, 자식 프로세스에서는 0 값을 반환 받음
            // fork() 실패 시 : -1 반환
            childPid = fork();
            // fork 함수를 호출하는 프로세스는 부모 프로세스가 되고 새롭게 생성되는 프로세스는 자식 프로세스
        
            // 부모 프로세스
            if(childPid > 0) {
                pid_t waitPid;
                printf("Parent PID : %ld, pid : %d %d \n",(long)getpid(),childPid, errno);
                
                // // 에러 발생시 명시적으로 처리하고, wait 함수를 재호출
                while((((waitPid = wait(&status)) == -1) && errno == EINTR));
                if(waitPid == -1) {
                    printf("Error Number : %d \n",errno);
                    perror("wait Error");
                }
                // 자식 프로세스 정상 종료WIFEXITED(statloc) 매크로가 true를 반환
                if(WIFEXITED(status)) {
                    printf("wait-Child Process Succeed(1) Exit %d\n",WEXITSTATUS(status));
                }
                // 자식 프로세스 비정상 종료 - WIFSIGNALED(statloc) 매크로가 true를 반환
                else if(WIFSIGNALED(status)) {
                    printf("wait-Child Process Faild(1) Exit %d\n",WTERMSIG(status));
                }
                printf("Parent Exit %d %d\n",waitPid,WTERMSIG(status));
            }
            // 자식프로세스 일 경우
            else if(childPid == 0){
                if(!strcmp(tokens[0],"cp")){
                    // 현재 작업 경로에 실행파일인 mycp를 가져오기 위한 경로 재설정
                    sprintf(local_path,"%s/%s",local_path,"mycp");
                    // 현재 작업 경로에 mycp 실행파일을 가져와서 명령어 실행
                    if(execl(local_path,"mycp",tokens[1],tokens[2], (char *)NULL) == -1){
                        perror("execlp");
                    }
                    printf("Child PID : %ld \n",(long)getpid());    // 자식 프로세스 PID 출력
                    printf("Child Exit\n"); // 자식 프로세스 종료 출력
                    exit(2); // 실행중인 현재 프로세스를 종료하는 시스템 콜 함수
                }
                else if(!strcmp(tokens[0],"mv")){// $mymv 명령으로 인자가 들어온 경우
                    // 현재 작업 경로에 실행파일인 mymv를 가져오기 위한 경로 재설정
                    sprintf(local_path,"%s/%s",local_path,"mymv");
                    // 현재 작업 경로에 mymv 실행파일을 가져와서 명령어 실행
                    if(execl(local_path,"mymv",tokens[1],tokens[2], (char *)NULL) == -1){
                        perror("execl");
                    }
                    printf("Child PID : %ld \n",(long)getpid());    // 자식 프로세스 PID 출력
                    printf("Child Exit\n"); // 자식 프로세스 종료 출력
                    exit(2); // 실행중인 현재 프로세스를 종료하는 시스템 콜 함수
                }
                else if(!strcmp(tokens[0],"date")){
                    // 현재 작업 경로에 실행파일인 date를 가져오기 위한 경로 재설정
                    sprintf(local_path,"%s/%s",local_path,"mydate");
                    // 현재 작업 경로에 date 실행파일을 가져와서 명령어 실행
                    if(execl(local_path,"mydate",tokens[1],tokens[2],(char *)NULL) == -1){
                        perror("date");
                    }
                    printf("Child PID : %ld \n",(long)getpid());    // 자식 프로세스 PID 출력
                    printf("Child Exit\n");     // 자식 프로세스 종료 출력
                    exit(2); // 실행중인 현재 프로세스를 종료하는 시스템 콜 함수
                }
                else{
                    if(execvp(tokens[0],tokens) == -1){
                        perror("execvp");       // execvp() 에러 출력
                    }
                }
            }
            else{
                perror("Child Process falied \n");      // 프로세스 생성 실패 에러 출력
                return -1;
            }
        }
    }
    return 0;
}
