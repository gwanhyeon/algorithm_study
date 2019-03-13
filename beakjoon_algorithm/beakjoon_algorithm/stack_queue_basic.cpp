//
//  stack_queue_basic.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void){
    stack<int> s;
    queue<int> q;
    
    // stack 처리하기
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);
    
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    
    // queue 처리하기
    cout << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.push(30);
    
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
// q 10 20 30 first in first out fifo
// stack last in first out

