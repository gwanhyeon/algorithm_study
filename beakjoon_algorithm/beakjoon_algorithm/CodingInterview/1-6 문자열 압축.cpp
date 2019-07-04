//
//  1-6 문자열 압축.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str = "aabccccaaa";
    string str_cpy;
    int cnt = 0;
    
    for(int i=0; i<str.size(); i++){
        // 맨처음들어 올 때 처리해주기, else로 처리하면 a값이 처리안된다.
        cnt++;
        if(str[i] != str[i+1]){
            str_cpy += (str[i] + to_string(cnt));
            cnt = 0;
        }
    }
    if(str.size() < str_cpy.size()){
        cout << str;
    }else{
        cout << str_cpy;
    }
    
    
    
    
}

