//
//  sort_STL3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 벡터는 연결리스트 용도로 사용한다.

bool compare(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
    
    if(a.second.first == b.second.first){
        // 더 어린학생이 우선순위가 높게 한다 내림차순 형식이다
        return a.second.second > b.second.second;
    } else {
        return a.second.second < b.second.second;
    }
    
}
int main(void){
    // 단일 페어
    vector<pair<int,string>> v;
    v.push_back(pair<int,string>(40,"kgh"));
    v.push_back(pair<int,string>(10,"kgh1"));
    v.push_back(pair<int,string>(30,"kgh2"));
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        cout << v[i].second;
    }
    
    // 이중 페어
    
    vector<pair<string,pair<int,int>>> v1;
    v1.push_back(pair<string,pair<int,int>>("Test4",pair<int,int>(60,10000)));
    v1.push_back(pair<string,pair<int,int>>("Test1",pair<int,int>(70,20000)));
    v1.push_back(pair<string,pair<int,int>>("Test2",pair<int,int>(40,30000)));
    v1.push_back(pair<string,pair<int,int>>("Test3",pair<int,int>(30,40000)));
    
    sort(v1.begin(),v1.end(),compare);
    
    for(int i=0; i<v1.size(); i++){
        cout << v1[i].first;
        
    }
    
    
    return 0;
}

