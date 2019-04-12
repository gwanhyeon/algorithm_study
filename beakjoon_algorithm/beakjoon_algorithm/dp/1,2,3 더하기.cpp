//
//  1,2,3 더하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[11];
int recursive(int n){
    
    // 1의 경우의 수
    if(n == 1){
        return 1;
    }
    // 2의 경우의 수
    if(n == 2){
        return 2;
    }
    // 3의 경우의 수
    if(n == 3){
        return 4;
    }
    // 메모이제이션
    if(dp[n]){
        return dp[n];
    }
    // 재귀 호출
    dp[n] = recursive(n-1) + recursive(n-2) + recursive(n-3);
    return dp[n];
    
}
int main(void){
    int t=0;
    cin >> t;
    // TEST CASE
    while(t--){
        int n;
        cin >> n;
        int result = recursive(n);
        cout << result << "\n";
        
    }
    return 0;
}
