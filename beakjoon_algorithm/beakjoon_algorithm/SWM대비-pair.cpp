//
//  SWM대비-pair.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
    if(a.second.first == b.second.first){
        return a.second.second > b.second.second;
        // 어린순서대로 출력해주기
    }else{
        return a.second.first > b.second.first;
    }
    
}
int main(void){
//    학생을 나타낼 수 있는 정보가 이름, 성적, 생년월일일 때 학생을 성적 순서대로 나열하고자 한다. 다만 성적이 동일한 경우 나이가 더 어린 학생이 더 우선순위가 높다.
    
    vector<pair<string,pair<int,int>>> v;
    
    

    v.push_back(pair<string,pair<int,int>>("a",make_pair(99, 940525)));
    v.push_back(pair<string,pair<int,int>>("b",make_pair(98, 940525)));
    v.push_back(pair<string,pair<int,int>>("c",make_pair(99, 950525)));
    v.push_back(pair<string,pair<int,int>>("d",make_pair(26, 940525)));
    sort(v.begin(), v.end(),compare);
    
    for(int i=0; i<v.size(); i++){
        
        cout << v[i].first;
    }
    
    
   
    
    
    
    
    return 0;
}
