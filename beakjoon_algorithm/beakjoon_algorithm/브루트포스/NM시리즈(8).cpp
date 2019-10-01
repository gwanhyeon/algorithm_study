//
//  NM시리즈(8).cpp
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
int n,m;
vector<int> res;
int arr[10001];
int check[10001];

// 중복 조합 비내림차순
void go(int index, int cnt){
    if(cnt == m){
        for(int i=0; i<res.size(); i++){
            cout << res[i] << ' ';
            if(i == m-1){
                cout << '\n';
            }
        }
        return;
    }
    
    for(int i=index; i<n; i++){
        
        res.push_back(arr[i]);
        go(i, cnt+1);
        res.pop_back();
        
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    go(0,0);
    
    return 0;
}
