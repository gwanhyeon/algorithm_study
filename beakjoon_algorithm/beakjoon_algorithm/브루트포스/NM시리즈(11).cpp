//
//  NM시리즈(11).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int n,m;
int arr[10001];
int check[10001];
vector<int> res;
set<string> s;
void go(int index, int cnt){
    if(cnt == m){
        bool tf = false;
        string str = "";
        for(int i=0; i<res.size(); i++){
            char a = res[i] + '0';
            str = str + a;
        }
        if(s.find(str) == s.end()){
            s.insert(str);
            tf = false;
            
        }else {
            tf = true;
        }
        if(tf == false){
            for(int i=0; i<res.size(); i++){
                cout << res[i] << ' ';
                
            }
            cout << '\n';
        }
        return;
    }
    
    for(int i=0; i<n; i++){
        
        res.push_back(arr[i]);
        go(i,cnt+1);
        res.pop_back();
    }
}
int main(void){
    //중복순열
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    go(0,0);
    return 0;
}

