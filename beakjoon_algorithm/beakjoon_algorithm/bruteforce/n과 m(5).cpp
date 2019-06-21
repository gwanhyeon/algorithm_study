//
//  n과 m(5).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
// 다시풀기

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
