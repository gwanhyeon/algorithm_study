//
//  NM시리즈(9).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
#include <string>

using namespace std;
int n,m;
int arr[10001];
int check[10001];
vector<int> res;
set<string> s;

// 순열
void go(int cnt){
    if(cnt == m){
        // 중복체크
        bool tf = false;
        string str;
        for(int i=0; i<res.size(); i++){
            char a = res[i] + '0';
            str = str + a;
        }
        // not found
        if(s.find(str) == s.end()){
            s.insert(str);
            tf = false;
        }else{
            tf = true;
        }
        
        if(tf == false){
            for(int i=0; i<res.size(); i++){
                cout << res[i] << ' ';
            }
        }
        
        return;
    }
    for(int i=0; i<n; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        res.push_back(arr[i]);
        go(cnt+1);
        check[i] = 0;
        res.pop_back();
    }
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        
    }
    sort(arr,arr+n);
    go(0);
    
    
    
    return 0;
}
