#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
using namespace std;
typedef struct _Student{
    char lastname[20];
    char firstname[20];
    char ssn[20];
    char score1[5];
    char score2[5];
    char score3[5];
    char score4[5];
    char score5[5];
    char grade[20];
    float avg;
}Student;
void Insertion_Show(Student *st, int cnt){
    cout << "===============================================================================\n";
cout << "======================데이터베이스 추가된 성적표======================================\n";
    cout << "===============================================================================\n";
    for(int i=0; i<cnt-1; i++){
        cout << st[i].lastname <<" ";
        cout << st[i].firstname <<" ";
        cout << st[i].ssn << " ";
        cout << st[i].avg << " \n";
    }
}
void Grade_Show(Student *st,int cnt){
    char str[10];
    int num;
    //    등수(평균기준)를 입력받고, 해당 학생의 이름, 학번, 평균를
    cout << "===============================================================================\n";
    cout << "NNUT 의왕캠퍼스 성적 출력 프로그램" << "\n";
    cout << "등수(평균기준)를 입력하시면 해당 학생의 이름, 학번, 평균이 출력됩니다" << "\n";
    cout << "원하는 등수를 보고 싶으시면 등수를 입력하세요.종료를 원하시면 Q를 입력하세요" << "\n";
    cout << "프로그램을 종료하시는순간 새로운 데이터베이스가 추가 및 목록이 생성 됩니다." << "\n";
    cout << "프로그램을 종료를 원하시면 Q를 입력하세요" << "\n";
    cout << "===============================================================================\n";
    while(1){
        cin >> str;
        num = atoi(str);
        
        if (!strcmp(str,"Q")){
            break;
        }
        if(num < cnt-1 ){
            
            cout << st[num].lastname << " ";
            cout << st[num].firstname << " ";
            cout << st[num].ssn << " ";
            cout << st[num].avg << endl;
        }else{
            cout << "해당 등수에 드는 학생이 없습니다." << endl;
            cout << "다시 입력 하세요." << endl;
        }
        
        
        
    }
    
    cout << "\n";

}
void Sort_Show(Student *st,int cnt){
  
        cout << "===============================================================================\n";
        cout << "===================유닉스프로그래밍 중간/기말고사 성적순==================================\n";
        cout << "===============================================================================\n";
    for(int i=0; i<cnt-1; i++){
        cout << st[i].lastname <<" ";
        cout << st[i].firstname <<" ";
        cout << st[i].ssn << " ";
        cout << st[i].avg << " \n";
        
    }
    cout << "\n";
}
void Current_Show(Student *st,int cnt){

    cout << st[cnt].lastname <<" ";
    cout << st[cnt].firstname <<" ";
    cout << st[cnt].ssn << " ";
    cout << st[cnt].score1 <<" ";
    cout << st[cnt].score2 <<" ";
    cout << st[cnt].score3 <<" ";
    cout << st[cnt].score4 <<" ";
    cout << st[cnt].score5 <<" ";
    cout << st[cnt].grade <<" ";
    cout << st[cnt].avg << " \n";
}

void Sort(Student *st, int cnt) {
    Student tmp;
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j < cnt; j++) {
            if (st[j-1].avg < st[j].avg) {
                //두 명의 데이터 교환
                tmp = st[j - 1];
                st[j - 1] = st[j];
                st[j] = tmp;
            }
        }
    }
    
    
}
int New_Student_Create(Student *st,int cnt){
    Student* st_new = (Student*)malloc( sizeof(Student));
      string filePath = "/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades1.csv";
    ifstream openFile(filePath.data());
    cnt--;
    int new_cur = cnt;
    
    if( openFile.is_open() ){
        string line;
        while(getline(openFile, line)){
            // 5. string -> char*
            
            vector<char> writable(line.begin(), line.end());
            writable.push_back('\0');
            char* ptr = &writable[0];
            // 6. strtok
            char *ptr_tok = strtok(ptr, " \",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            int i = 0;
            char *store[30];
            while (ptr_tok != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                store[i] = ptr_tok;
                i++;
                ptr_tok = strtok(NULL," \",");
            }
            i =0;
            
            //          출력
            if(cnt == new_cur){
                cout << "=====새로운 데이터베이스가 추가 됩니다.\n";
            }else{
                
                strcpy(st[cnt].lastname,store[i++]);
                strcpy(st[cnt].firstname,store[i++]);
                strcpy(st[cnt].ssn,store[i++]);
                strcpy(st[cnt].score1,store[i++]);
                strcpy(st[cnt].score2,store[i++]);
                strcpy(st[cnt].score3,store[i++]);
                strcpy(st[cnt].score4,store[i++]);
                strcpy(st[cnt].score5,store[i++]);
                strcpy(st[cnt].grade,store[i++]);
                
                float temp_avg = ((atof(st[cnt].score1) + atof(st[cnt].score2) + atof(st[cnt].score3) +
                                   atof(st[cnt].score4) + atof(st[cnt].score5)) / 5);
                st[cnt].avg = temp_avg;
//                Current_Show(st,cnt);
            }
            cnt++;
        }
    }
//    cout << "여기는 " << cnt;
    cout << "\n";
    return cnt;
    
}


int main(void){
//    Student *st = (Student*)malloc(sizeof(Student));
    Student st[100];
    string filePath = "/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades.csv";
    // read File
    ifstream openFile(filePath.data());
    // 1. 파일 오픈
    int cnt=0;
    if( openFile.is_open() ){
        // 2. 입력
        string line;
        // 3. 파일 인풋
        
        // 4. 파일 READ
        while(getline(openFile, line)){
            // 5. string -> char*
            
            vector<char> writable(line.begin(), line.end());
            writable.push_back('\0');
            char* ptr = &writable[0];
            // 6. strtok
            char *ptr_tok = strtok(ptr, " \",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            string str;
            int i = 0;
            char *store[30];
            while (ptr_tok != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                store[i] = ptr_tok;
                i++;
                ptr_tok = strtok(NULL," \",");
            }
            i =0;
           
            //          출력
            if(cnt == 0){
                cout << "===============================================================================\n";
                cout << "===================유닉스프로그래밍 중간/기말고사 성적==================================\n";
                cout << "===============================================================================\n";
                cout << "lastName" << " ";
                cout << "firstName" << " ";
                cout << "SSN" << " ";
                cout << "test1" << " ";
                cout << "test2" << " ";
                cout << "test3" << " ";
                cout << "test4" << " ";
                cout << "final" << " ";
                cout << "Grade" << " ";
                cout << "Avg" << "\n";
                
            }else{
                
                strcpy(st[cnt].lastname,store[i++]);
                strcpy(st[cnt].firstname,store[i++]);
                strcpy(st[cnt].ssn,store[i++]);
                strcpy(st[cnt].score1,store[i++]);
                strcpy(st[cnt].score2,store[i++]);
                strcpy(st[cnt].score3,store[i++]);
                strcpy(st[cnt].score4,store[i++]);
                strcpy(st[cnt].score5,store[i++]);
                strcpy(st[cnt].grade,store[i++]);
                
                float temp_avg = ((atof(st[cnt].score1) + atof(st[cnt].score2) + atof(st[cnt].score3) +
                                   atof(st[cnt].score4) + atof(st[cnt].score5)) / 5);
                st[cnt].avg = temp_avg;
                Current_Show(st,cnt);
            }
            cnt++;
            
            
        }
    }
    cout<< "\n";
//    sort(&st,&st+sizeof(st));
    Sort(st,cnt);
    Sort_Show(st,cnt);
    Grade_Show(st,cnt);
    int new_cnt = New_Student_Create(st,cnt-1);
    Insertion_Show(st,new_cnt);
    Sort(st,new_cnt);
    Sort_Show(st,new_cnt);
//    Grade_Show(st,new_cnt);
    
    memset(&st, 0, sizeof(st));
    
    openFile.close();
//    free(st);

    return 0;
}

