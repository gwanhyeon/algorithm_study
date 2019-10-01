//
//  NM시리즈(6).cpp
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
int arr[10001];
int check[10001];
vector<int> res;

// 조합 중복 X
void go(int index,int cnt){
    if(cnt == m){
        for(int i=0; i<res.size(); i++){
            cout << res[i] << ' ';
        }
        cout<< '\n';
        return;
    }
    
    for(int i=index; i<n; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        res.push_back(arr[i]);
        go(i,cnt+1);
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
    go(0,0);
    
    
    return 0;
}
