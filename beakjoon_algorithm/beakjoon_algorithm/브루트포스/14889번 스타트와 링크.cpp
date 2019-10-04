//
//  14889번 스타트와 링크.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int n;
int arr[101][101];
int check[101][101];
vector<int> res;

void go(int index,int cnt){
    
    if(cnt == n/2){
        
    }
    int sum = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 1){
                continue;
            }
            check[i][j] = 1;
            res.push_back(arr[i][j]);
            sum = arr[i][j] + arr[j][i];
            go(sum,cnt);
            check[i][j] = 0;
            res.pop_back();
        }
    }
}

int main(void){
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    go(0,0);
    
    
    
    return 0;
}
