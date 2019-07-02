//
//  하나빼기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// 삽입 삭제 교체

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str1 = "pale";
    string str2 = "ple";
    int cnt=0;
    
    
    if(str1.size() - str2.size() == 0){
        for(int i=0; str1.size(); i++){
            if(str1[i] != str2[i]){
                cnt++;
            }else {
                continue;
            }
        }
        
    }else if(str1.size() - str2.size() == 1){       // str1.size() > str2.size()
        for(int i=0; i<str2.size(); i++){
            if(str1[i] != str2[i]){
                cnt++;
            }else{
                continue;
            }
        }
    }else if(str2.size() - str1.size() == 1){        // str1.size() < str2.size()
        for(int i=0; i<)
    }
    
    return 0;
}

