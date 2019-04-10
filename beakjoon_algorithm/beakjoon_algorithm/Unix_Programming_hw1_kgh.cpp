//
//  Unix_Programming_hw1_kgh.cpp
//  Created by kgh on 5/4/2019.
//  Copyright © 2019 kgh. All rights reserved.
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
// 학생 구조체 선언(변수: lastname,firstname,ssn,score1,2,3,4,5, grade, avg)

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

// ## 1.함수 선언 ##
// Insertion_Show 함수 : 새로운 데이터베이스 삽입이후에 출력시켜주는 함수
void Insertion_Show(Student *st, int cnt);
// Sort_Show 함수 : 정렬된 이후에 구조체 값 출력시켜주는 함수
void Sort_Show(Student *st,int cnt);
// Current 함수: 현재 데이터베이스 상태를 출력해주는 함수
void Current_Show(Student *st,int cnt);
// New_Student_Create : 새로운 파일을 읽어들여 구조체에 추가 시키는 함수
int New_Student_Create(Student *st,int cnt);
// Grade_Show : 성적 출력 함수
void Grade_Show(Student *st,int cnt);

// ## 1. 함수구현 ##
void Grade_Show(Student *st,int cnt){
    char str[10];       // 등수값을 받기위한 변수
    int num;            // 몇등인지 파악 하기 위한 변수
    cout <<
"===============================================================================\n";
    cout << "KNUT 의왕캠퍼스 성적 출력 프로그램" << "\n";
    cout << "등수(평균기준)를 입력하시면 해당 학생의 이름, 학번, 평균이 출력됩니다" << "\n";
    cout << "원하는 등수를 보고 싶으시면 등수를 입력하세요.종료를 원하시면 Q를 입력하세요" << "\n";
    cout << "프로그램을 종료하시는순간 새파일에서 데이터베이스가 추가 및 목록이 생성 됩니다." << "\n";
    cout << "프로그램을 종료를 원하시면 Q를 입력하세요" << "\n";
    cout << "===============================================================================\n";
    //등수(평균기준)를 입력받고, 해당 학생의 이름, 학번, 평균을 출력시키는 기능
    while(true){
        cin >> str;
        num = atoi(str);
        // "Q"일경우 종료
        if (!strcmp(str,"Q")){
            break;
        }
        // 이름, 학번, 평균 출력
        if(num < cnt-1 ){
            cout << st[num].lastname << " ";
            cout << st[num].firstname << " ";
            cout << st[num].ssn << " ";
            cout << st[num].avg << endl;
        // 데이터베이스에 없는 값일 경우 재입력
        }else{
            
            cout << "해당 등수에 드는 학생이 없습니다." << endl;
            cout << "다시 입력 하세요." << endl;
        }
    }
    cout << "\n";
}
// Sort_Show 함수 : 정렬된 이후에 구조체 값 출력시켜주는 함수
void Sort_Show(Student *st,int cnt){
  
        cout << "===============================================================================\n";
        cout << "===================유닉스프로그래밍 중간/기말고사 성적순==================================\n";
        cout << "===============================================================================\n";
    // 성적순으로 정렬된 값을 출력시켜주기위한 반복문
    for(int i=0; i<cnt-1; i++){
        cout << st[i].lastname <<" ";
        cout << st[i].firstname <<" ";
        cout << st[i].ssn << " ";
        cout << st[i].avg << " \n";
    }
    cout << "\n";
}
// Current 함수: 현재 데이터베이스 상태를 출력해주는 함수
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

// Sort_Show 함수 : 정렬된 이후에 구조체 값 출력시켜주는 함수
void Sort(Student *st, int cnt) {
    Student tmp;        // Student 구조체에 잠시 담을 임시 구좇
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j < cnt; j++) {
            // 값 비교후 정렬 시간복잡도 면에서는 효율적이진 않음.
            if (st[j-1].avg < st[j].avg) {
                tmp = st[j - 1];
                st[j - 1] = st[j];
                st[j] = tmp;
            }
        }
    }
    
    
}
// New_Student_Create : 새로운 파일을 읽어들여 구조체에 추가 시키는 함수
int New_Student_Create(Student *st,int cnt){
//    Student* st_new = (Student*)malloc( sizeof(Student));
      string filePath = "/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades1.csv";
    ifstream openFile(filePath.data());
    cnt =0;
    // 문자열에 "\0값을 제거하기위함\"
    if(openFile.is_open() ){
        string line;
        // FILE에 한줄씩 읽어 들인다.
        while(getline(openFile, line)){
            // string to char*
            vector<char> writable(line.begin(), line.end());
            writable.push_back('\0');
            char* ptr = &writable[0];
            // strtok으로 문자열 자르기
            char *ptr_tok = strtok(ptr, " \",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            int i = 0;
            // 값을 임시 저장하기 위한 변수
            char *store[30];
            while (ptr_tok != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                store[i] = ptr_tok;
                i++;
                ptr_tok = strtok(NULL," \",");
            }
            i =0;
            
            //출력
            if(cnt == 0){
                cout << "===============================================================================\n";
                cout << "===================새로운 파일 데이터입니다.==================================\n";
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
                // string 값 copy
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
    cout << "\n";

    return cnt;
    
    
    
}


int main(void){
//    Student *st = (Student*)malloc(sizeof(Student));
    int Student_Num = 100;
    Student *st = (Student*)malloc(sizeof(Student)*Student_Num);
    Student *st_new = (Student*)malloc(sizeof(Student)*Student_Num);
    
//    Student st[100];
    string filePath = "/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades.csv";
    // read File
    ifstream openFile(filePath.data());
    // 1. 파일 오픈
    int cnt=0;
    if( openFile.is_open() ){
        // csv File Read
        string line;
        // FILE에 한줄씩 읽어 들인다.
        while(getline(openFile, line)){
            // string to char*
            vector<char> writable(line.begin(), line.end());
            writable.push_back('\0');
            char* ptr = &writable[0];
            // // | , 기준으로 값을 strtok시켜준다.
            char *ptr_tok = strtok(ptr, " \",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            string str;
            int i = 0;
            // string 값을 담기 위한 변수
            char *store[30];
            // | , 기준으로 값을 strtok시켜준다.
            while (ptr_tok != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                store[i] = ptr_tok;
                i++;
                ptr_tok = strtok(NULL," \",");
            }
            i =0;
           
            //출력
            if(cnt == 0){
                cout << "===============================================================================\n";
                cout << "===================유닉스프로그래밍 중간/기말고사 성적==================================\n";
                cout << "===============================================================================\n";
                cout << "lastName" << "\t";
                cout << "firstName" << "\t";
                cout << "SSN" << " \t";
                cout << "test1" << "\t";
                cout << "test2" << "\t";
                cout << "test3" << "\t";
                cout << "test4" << "\t";
                cout << "final" << "\t";
                cout << "Grade" << "\t";
                cout << "Avg" << "\n";
                
            }else{
                // store에 값을 담아서 st구조체에 값을 넣어준다.
                strcpy(st[cnt].lastname,store[i++]);
                strcpy(st[cnt].firstname,store[i++]);
                strcpy(st[cnt].ssn,store[i++]);
                strcpy(st[cnt].score1,store[i++]);
                strcpy(st[cnt].score2,store[i++]);
                strcpy(st[cnt].score3,store[i++]);
                strcpy(st[cnt].score4,store[i++]);
                strcpy(st[cnt].score5,store[i++]);
                strcpy(st[cnt].grade,store[i++]);
                // flaot형태로 평균값을 계산하기위해 atof로 변환 int to float
                float temp_avg = ((atof(st[cnt].score1) + atof(st[cnt].score2) + atof(st[cnt].score3) +
                                   atof(st[cnt].score4) + atof(st[cnt].score5)) / 5);
                st[cnt].avg = temp_avg;
                Current_Show(st,cnt);
            }
            cnt++;
        }
    }
    cout<< "\n";
    Sort(st,cnt);       // 구조체 정렬
    Sort_Show(st,cnt);      // 구조체 값 출력
    Grade_Show(st,cnt);     // 이름 학생 성적만 출력
    int new_cnt = 0;
    new_cnt = New_Student_Create(st_new,new_cnt); // 새로운 파일을 읽어들여 데이터베이스 추가
//    Insertion_Show(st_new,new_cnt); // 삽입된 값들만 출력
    Sort(st_new,new_cnt);       // 기존의 값 + 삽입된 값 구조체 정렬
    Sort_Show(st_new,new_cnt);  // 기존의 값 + 삽입된 값 구조체 출력

    
    
    // 메모리초기화
    memset(&st, 0, sizeof(st));
    memset(&st_new, 0, sizeof(st_new));
    openFile.close();
    return 0;
}


