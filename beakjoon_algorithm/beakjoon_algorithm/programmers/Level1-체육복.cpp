//
//  Level1-체육복.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
bool check[30];
using namespace std;
int main(void){
    int n=5;
    vector<int> lost;
    vector<int> reserve;
    lost.push_back(2);lost.push_back(4);        // lost st
    reserve.push_back(1); reserve.push_back(3); // reverse st
    reserve.push_back(5);
    
    vector<int> student(n,1);
    int answer = 0;
    // lost students
    for(int i=0; i<lost.size(); i++){
        student[lost[i]]--;
    }
    
    // reserve students
    for(int i=0; i<reserve.size(); i++){
        student[reserve[i]]++;
    }
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(student[lost[i]] == student[reserve[j]]){
                student[lost[i]]--;
                student[reserve[j]]--;
            }
        }
    }

    for(int i=0; i<student.size(); i++){
        
        if(i != 0 && student[i-1] == 0){
            if(student[i] == 2){
                student[i]--;
                student[i-1]++;
            }
        }
        if(i != student.size() && student[i+1] == 0){
            if(student[i] == 2 ){
                student[i]--;
                student[i+1]++;
            }
        }
    }
    for(int i=0; i<student.size(); i++){
        if(student[i] > 0){
            answer++;
        }
    }
    cout << answer;
    return 0;
}
