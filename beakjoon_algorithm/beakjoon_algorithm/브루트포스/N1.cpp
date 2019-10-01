//
//  N1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
종류별로 종류 같게
최대 1장만 더 살 수 있음
output 만약 같은 종류가 될 수 없으면, NO

 a b a a
 
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(void){
    
    int n;
    vector<string> v(n);
    map<string,int> m;
    
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    
    for(int i=0; i<n; i++){
        // not found
        if(m.find(v[i]) == m.end()){
            m[v[i]]=1;
            
        }else {
            m[v[i]]++;
        }
    }
    
    vector<int> res;
    int sum = 0;
    int YN = 0;
    map<string, int>::iterator max_iter = m.begin();
    for(auto it = m.begin(); it != m.end(); it++){
        // 종류가 같지 않을때
        if(max_iter->second != it->second){
            it->second++;
        }
        if(max_iter->second == it->second) {
            YN++;
        }
        sum += it->second;
    }
    
    if(YN == m.size()){
        cout << "Y" << '\n';
    }else {
        cout << "NO" << '\n';
    }
    
    cout << sum << '\n';
    cout << YN << '\n';


    return 0;
}
