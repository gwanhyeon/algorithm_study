//
//  10799 쇠막대기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main(void){
    stack<int> s;
    string str;
    cin >> str;
    int answer = 0;
    int len = str.size();
    
    for(int i=0; i<len; i++){
        if(str[i] == '('){
            s.push(str[i]);
        }else {
            s.pop();
            if(str[i-1] == '('){
                answer += s.size();
            }else {
                answer += 1;
            }
        }
    }
    
    cout << answer << '\n';
    
    
    
    return 0;
}
