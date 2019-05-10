//
//  링크드리스트.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
#include <list>
// linked list 를 코딩테스트에서 구현해야할 경우에는 vector를 사용해서 구현하는것이 마음이 편하다
using namespace std;
// STL list
int main(void){
    list<int> L = {1,2};        // {1->2}
    list<int>::iterator t = L.begin();
    // auto t = L.begin();
    L.push_front(10);       // {10,1,2}
    cout << *t << '\n';         // t가 현재 가리키는 값은 1이다.
    L.push_back(5); //{10,1,2,5}
    L.insert(t,6);  // {10,6,1,2,5}
    t++; // t를 1칸 앞으로 전진, 현재 5가 가리키는 값은 2   {10,6,1,2,5} t = 2
    t = L.erase(t);     //t가 가르키는값을 제거하고 그다음값인 5를 가르키게 한다.
    
    t = L.end();
    
    for(auto i : L){
        cout << i << ' ';
    
    }
    
    
    
    
}
