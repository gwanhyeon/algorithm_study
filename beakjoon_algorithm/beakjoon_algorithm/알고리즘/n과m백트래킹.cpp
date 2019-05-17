
//
//  n과m백트래킹.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


#include <bits/stdc++.h>
using namespace std;

int n,m;

void recursive(int* arr, int* isused, int k){
    
    if(k == m){
        for(int i=0; i<m; i++){
            cout << arr[i] + 1 << ' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            recursive(arr,isused,k+1);
            isused[i] = 0;
        }
    }
    
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // n은 몇개의 상위 트리 인지,
    // m은 몇개의 범위 까지 처리할것인지
    
    cin >> n >> m;
    
    int arr[m] = {0,};
    bool isused[n] = {0,};
    recursive(arr,isused, 0);
    
    return 0;
}
