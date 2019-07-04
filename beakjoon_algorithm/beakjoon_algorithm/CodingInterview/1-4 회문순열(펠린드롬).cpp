//
//  1-4회문순열(펠린드롬).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//# 풀이 reverse , compare # bitvector

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main(void){
    string str = "HHHHHH";
    bool flag = true;
    int size = str.size();
    
    // permutation
    sort(str.begin(), str.end());
    
    // palindrome
    for(int i=0; i<size/2; i++){
        if(str[i] != str[size-i-1]){
            flag = false;
            break;
        }
    }
    if(flag == true){
        cout << "순열이며 펠린드롬 입니다" <<flag;
    }else{
        cout << "순열이며 펠린드롬이 아닙니다" <<flag;
    }
    return 0;
}

