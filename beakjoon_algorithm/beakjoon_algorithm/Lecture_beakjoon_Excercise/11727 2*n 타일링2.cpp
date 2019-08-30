//
//  11727 2*n 타일링2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1001];

int main(void){
    int n;
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 3;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+(2*dp[i-2]);
        dp[i] %= 10007;
        
    }
    cout << dp[n-1] << '\n';
    
    return 0;
}
