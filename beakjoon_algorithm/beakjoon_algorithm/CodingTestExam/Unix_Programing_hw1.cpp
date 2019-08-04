#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>


#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#define NUM 5
#define NUM_LENGTH 20
using namespace std;

typedef struct _Student{
    char lastname[20];
    char firstname[20];
    char ssn[20];
    char score[5][20];
    char grade[20];
    char store[100];
    
}Student[100];



int main(void){
    Student *st = (Student*)malloc(sizeof(Student));
    string filePath = "/Users/kgh/Development/Algorithm_CodingTest/algorithm_study/beakjoon_algorithm/beakjoon_algorithm/grades.csv";
    int cnt = 0;

    // read File
    ifstream openFile(filePath.data());
    // 1. 파일 오픈
    if( openFile.is_open() ){
        // 2. 입력
        string line;
        // 3. 파일 인풋
        char *store;
        int cnt;
        while(getline(openFile, line)){
            // 4. vector
            
            vector<char> writable(line.begin(), line.end());
            writable.push_back('\0');
            char* ptr = &writable[0];
            // 5.
            char *ptr_tok = strtok(ptr, " \",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            string str;
            
                while (ptr_tok != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
                {
//                    store[a]= ptr_tok;
                    strcpy(st[0]->store,ptr_tok);
                    cout << st[0]->store << endl;
                    strcpy(st[cnt]->lastname, ptr_tok);
                    cout << st[cnt]->lastname;
//                    str.append(ptr_tok);
//                    str.append(" ");
//                    cout << str << " ";
//                    cout << store[a] << " ";
//                    cout << ptr_tok << " ";
            
                    ptr_tok = strtok(NULL," \",");
                    cnt++;
                }
            cout << cnt;
            
//            cout << str;
//            cout << endl;
            for(int i=0; i<cnt; i++){
                    strcpy(st[cnt]->lastname, &str[i]);

                    strcpy(st[cnt]->firstname, &str[i]);
                    strcpy(st[cnt]->ssn, &str[i]);
                    for(int j=0; j<5; j++){
                        strcpy(st[cnt]->score[j],&str[j]);
                    }
                    strcpy(st[cnt]->grade, &str[i]);
                }

            cnt++;
            // cout << line << endl;
          
        }
//
//        for(int i=0; i<sizeof(st); i++){
//            cout << st[i]->lastname << endl;
//            cout << st[i]->firstname << endl;
//            cout << st[i]->ssn << endl;
//            for(int j=0; j<5; i++){
//                cout << st[i]->score[j] << endl;
//            }
//            cout << st[i]->grade << endl;
//
//        }
//        free(st);
        
        openFile.close();
    }
 
    
    
    //     char s1[30] = "The Little Prince";  // 크기가 30인 char형 배열을 선언하고 문자열 할당
    
    //     char *ptr = strtok(s1, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
    
    //     while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    //     {
    //         printf("%s\n", ptr);          // 자른 문자열 출력
    //         ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환
    //     }
    return 0;
}
