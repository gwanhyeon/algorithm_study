//
//  쉬운계단수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
/*
 
 고민한번더 해보기!
 
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int dp[101];

int recursive(int m,int n){
    
    if(n == 0){
        return n;
    }
    if(dp[n]){
        return dp[n];
    }
    
    dp[n] = recursive(m,dp[m-n]);
    return dp[n];
}

int main(void){
    int m = 45656;
    int n;
    cin >> n;
    int result = recursive(m,n);
    cout << result;
    
    
    
    
    
    return 0;
}
