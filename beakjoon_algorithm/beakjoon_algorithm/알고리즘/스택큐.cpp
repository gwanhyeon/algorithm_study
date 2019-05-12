//
//  스택큐덱.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// Stack 쓰임새 = 수식의 괄호쌍, 전위/중위/후위 / DFS / Flood Fill
// stack이 되지않을 경우에는 배열로 간단하게 처리해주어도 됩니다.

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    S.push(10); // {10}
    S.push(20); // {10,20}
    S.push(30); // {10,20,30}
    // stack 자료구조형의 특징을 알고 계신가요?
    // last in first out LIFO
    
    cout << S.size() << '\n';
    // endl를 사용하지 않는 이유는요 endl buffer놈이 들어가있기때문에
    // endl 사용하는것보다는 지양해야하는 이유중 하나고, endl => '\n'로 대체하여서 사용하시면 됩니다.
    if(S.empty()){
        cout << "S is Empty" << '\n';
    }else{
        cout << "S is not Empty" << '\n';
    }
    // Stack = {10,20,30}
    S.pop(); // {10,20}
    S.pop(); // {10}
    
    if(S.empty()){
        cout << "S is empty\n";
    }else{
        cout << "S is not empty\n";
    }
}
