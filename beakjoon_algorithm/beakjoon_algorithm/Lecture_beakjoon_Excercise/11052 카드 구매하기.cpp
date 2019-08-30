//
//  11052 카드 구매하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1001];
int card[10001];
int main(void){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> card[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i],dp[i-j] + card[j]);
        }
    }
    
    cout << dp[n] << '\n';
    return 0;
}
