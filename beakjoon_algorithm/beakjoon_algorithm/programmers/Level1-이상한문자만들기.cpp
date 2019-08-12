//
//  Level1-이상한문자만들기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(void){
    string s = "try hello world";
    string answer;
    bool flag = true;
    for(int i=0; i<s.size(); i++){
        
        if(s[i] == ' '){
            answer += ' ';
            flag = true;
        }else {
            if(flag){
                flag = false;
                answer += toupper(s[i]);
            }else {
                flag = true;
                answer += tolower(s[i]);
            }
        }
    }
    for(auto a : answer){
        cout << a;
    }
    cout << '\n';
    return 0;
}
