//
//  n과 m(4).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// 비 내림차순에 중복선택가능
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int arr[10];
bool check[10];
void recursive(int index,int start,int n,int m){
    if(index == m){
        for(int i=0; i<m; i++){
            cout << arr[i];
            if(i != m-1){
                cout << ' ';
            }
        }
        cout <<'\n';
        return;
    }
    for(int i=start; i<=n; i++){
        arr[index] = i;
        check[index] = true;
        // i면 중복 허용 , i+1이면 중복허용 X
        recursive(index+1,i,n,m);
        check[index] = false; 
    }
}

int main(void){
    int n,m;
    cin >> n >> m;
    
    recursive(0,1,n,m);
    
    return 0;
}
