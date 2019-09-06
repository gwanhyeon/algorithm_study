//
//  N-Queen.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int map[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row,int col){
    // |
    if(check_col[col]){
        return false;
    }
    // 오른쪽 위방향(오른쪽 대각선)
    if(check_dig[row+col]){
        return false;
    }
    // 왼쪽 위방향(왼쪽 대각선)
    if(check_dig2[row-col+n]){
        return false;
    }
    return true;
}

// 행을 체크하는 경우임
int go(int row){
    int cnt = 0;
    if(row == n){
        return 1;
    }
    for(int col=0; col<n; col++){
        if(check(row,col)){
            check_dig[row+col] = true;
            check_dig2[row-col+n] = true;
            check_col[col] = true;
            map[row][col] = true;
            cnt += go(row+1);
            check_dig[row+col] = false;
            check_dig2[row-col+n] = false;
            check_col[col] = false;
            map[row][col] = false;
        }
    }
    return cnt;
}

int main(void){
    
    cin >> n;
    cout << go(0) << '\n';
    
    return 0;
    
}
