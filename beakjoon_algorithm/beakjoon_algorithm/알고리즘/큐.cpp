//
//  큐.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// Queue First In First Out
// 줄 선 순서대로 처리하느것을 의미합니다.
// 예를 들어볼까요? 은행에서 줄서기
// BFS, Flood Fill
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    queue<int> Q;
    Q.push(10); // {10}
    Q.push(20); // {10,20}
    Q.push(30); // {10,20,30}
    
    cout << Q.size() << '\n';  // {3}

    if(Q.empty()){
        cout << "Queue is Empty" << '\n';
    }else{
        cout << "Queue is not Empty" << '\n'; // {10,20,30}
    }
    
    Q.pop(); // {First In First out => 20, 30}
    Q.push(40);         // {20,30,40};
    
    cout << Q.front() << '\n'; // {20}
    cout << Q.back() << '\n';   // {40};
    
    return 0;
}
