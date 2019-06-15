//
//  n과 m(3).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

int arr[10];
bool check[10];

void recursive(int index,int n,int m){
    
    if(index==m){
        for(int i=0; i<m; i++){
            cout << arr[i];
            if(i != m-1){
                cout << ' ';
            }
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        // 중복선택이 가능하므로, 주석 제거 해준다.
        
        arr[index] = i;
        check[index] = true;
        recursive(index+1,n,m);
        check[index] = false;
        
    }
    
    
}
int main(void){
    int n,m;
    cin >> n >> m;
    
    recursive(0,n,m);
    
    return 0;
    
}
