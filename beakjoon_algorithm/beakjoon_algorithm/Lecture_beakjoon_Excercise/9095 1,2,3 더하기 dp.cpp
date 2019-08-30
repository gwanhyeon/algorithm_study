//
//  9095 1,2,3 더하기 dp.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int dp[11];

int recursive(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 4;
    }
    
    if(dp[n] > 0){
        return dp[n];
    }
    
    dp[n] = (recursive(n-1) + recursive(n-2) + recursive(n-3)) % 1000000009;
    return dp[n];
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << recursive(n) << '\n';
    }
    return 0;
}
