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
    string str_copy;
    int cnt = 0;
    char store=NULL;
    for(int i=0; i<str.size(); i++){
        
        for(int j=i+1; j<str.size(); j++){
            if(str[i] == str[j]){
                store = str[i];
                cnt++;
            }else{
                str_copy += (store+cnt);
                cnt =0;
            }
        }
    }
    if(str.size() < str_copy.size()){
        cout << str;
    }else{
        cout << str_copy;
    }
    
}

