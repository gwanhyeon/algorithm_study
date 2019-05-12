//
//  덱.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
// 양쪽 삽입 삭제가 일어나는
// STL Deque

int main(void){
    deque<int> DQ;
    DQ.push_back(10);  // {10}
    DQ.push_back(40); // {10,40}
    DQ.push_front(20); // {20,10,40}
    cout << DQ.size() << '\n'; // {3}
    cout << DQ.back() << '\n'; // {40}
    
    if(DQ.empty()){
        cout << "Deque is Empty" << '\n';
    }else{
        cout << "Deque is not Empty" << '\n';
    }
    
    DQ.pop_front(); // {10,40}
    DQ.push_back(20);// {10,40,20}
    DQ.pop_back();  // {10,40}
    
    cout << DQ.front() << '\n'; // {10}
    cout << DQ[0] << ' ' << DQ[1] << '\n'; // {10,40}
    
    
    
    return 0;
}
