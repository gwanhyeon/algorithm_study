//
//  프로그래머스 쇠막대기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
int main(void){
    string str ="()(((()())(())()))(())";
    stack<int> s;
    int sum = 0;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            s.push(str[i]);
        }else {
            s.pop();
            if(str[i-1] == '('){
                sum += s.size();
            }else {
                sum += 1;
            }
        }
    }
    cout << sum << ' ';
}
