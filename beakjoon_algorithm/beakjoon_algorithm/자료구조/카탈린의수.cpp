//
//  카탈린의수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int paren_count;
vector<string> answer = {};

void print(int *arr, int arr_size){
    string str;
    for(int i=0;i < arr_size; i++){
        
        if(arr[i] == 'L'){
            str.append("(");
            //            cout << "(";
        }else{
            //            cout << ")";
            str.append(")");
        }
    }
    answer.push_back(str);
    cout << endl;
}
void solution2(int* arr, int arr_size, int open,int close){
    if(open == 0 && close == 0){
        print(arr,arr_size);
        paren_count++;
        return;
    }
    if(open >0){
        arr[arr_size] = 'L';
        solution2(arr,arr_size+1,open-1,close+1);
    }
    if(close >0){
        arr[arr_size] = 'R';
        solution2(arr,arr_size+1,open,close-1);
    }
}


vector<string> solution(int N)
{
    int* num_list = new int[N];
    solution2(num_list,0,N,0);
    
    return answer;
}
