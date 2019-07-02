//
//  벡터.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <bits/stdc++.h>
//#include <stdio.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v1(3,5);        // {5,5,5}
    cout << v1.size() <<'\n';   // {3}
    v1.push_back(7);            // {5,5,5,7}
    
    // v1 i = 0 ~ 2^32-1 까지 돌게되는데, 여기서 vector는 unsigend int와 연산결과는 unsinged int 형변환이 일어나므로 -1을 빼주지말아야한다. -1을 빼주게 된다면 비어있는값이 있는경우 심각한 결과를 일으키게 한다.
    for(int i=0; i<v1.size(); i++){
        cout << v1[i];
    }
    cout << "\n";
    vector<int> v2(2);          // {0,0}
    cout << v2.size() << '\n';  // {2}
    v2.insert(v2.begin()+1, 3);    // {0,3,0}
    
    vector<int> v3 = {1,2,3,4};     // {1,2,3,4}
    v3.erase(v3.begin()+2);         // {1,2,4}  3만 삭제
    vector<int> v4;
    v4 = v3;
    
    cout << v4[0] << ' ' << v4[1] << ' ' << v4[2] << '\n';
    v4.pop_back();
    v4.clear();
}
