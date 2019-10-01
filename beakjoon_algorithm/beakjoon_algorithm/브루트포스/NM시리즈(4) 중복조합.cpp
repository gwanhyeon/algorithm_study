//
//  NM시리즈(4).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
int check[10];

void go(int cnt){
    if(cnt == m){
        bool tf = false;
        if(m == 1){
            tf = true;
        }else{
            for(int i=0; i<v.size()-1; i++){
                if(v[i] > v[i+1]){
                    tf = false;
                }else if(v[i] < v[i+1]){
                    tf = true;
                }
            }
        }
        if(tf == true){
            for(int i=0; i<v.size(); i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for(int i=0; i<n; i++){
        v.push_back(i+1);
        go(cnt+1);
        v.pop_back();
    }
}

//중복 조합이다
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    go(0);
    
}
