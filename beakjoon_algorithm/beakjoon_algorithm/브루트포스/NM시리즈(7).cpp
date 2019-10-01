//
//  NM시리즈(7).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//중복 순열
int n,m;
int arr[10001];
int check[10001];
vector<int> res;

void go(int cnt){
    
    if(cnt == m){
    
            for(int i=0; i<res.size(); i++){
                cout << res[i] << ' ';
            }
            cout << '\n';
        
        return;
    }
    
    for(int i=0; i<n; i++){
        res.push_back(arr[i]);
        go(cnt+1);
        res.pop_back();
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    go(0);
    
    
}
