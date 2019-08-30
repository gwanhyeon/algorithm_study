//
//  1463번 123만들기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[100];

int recursive(int n){
    
    if(n == 1){
        return 0;
    }
    if(dp[n] > 0){
        return dp[n];
    }
    // 반례 10의 경우
    dp[n] = recursive(n-1) + 1;
    if(n%2 == 0){
        int temp = recursive(n/2) + 1;
        if(dp[n] > temp){
            dp[n] = temp;
        }
    }
    if(n%3 == 0){
        int temp = recursive(n/3) + 1;
        if(dp[n] > temp){
            dp[n] = temp;
        }
    }
    return dp[n];
}
int main(void){
    int n;
    cin >> n;
    cout << recursive(n) << '\n';
    return 0;
}
