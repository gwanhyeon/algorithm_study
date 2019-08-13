//
//  Level1-자릿수더하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n = 123;
    string str = to_string(n);
    int answer = 0;
    for(int i=0; i<str.size(); i++){
        answer += str[i]-'0';
    }
    cout << answer;
    
}
