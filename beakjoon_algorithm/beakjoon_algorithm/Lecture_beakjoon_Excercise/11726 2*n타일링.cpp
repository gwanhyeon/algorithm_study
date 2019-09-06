//
//  11726 2*n타일링.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1001];

int recursive(int n){
    
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    
    if(dp[n] > 0 ){
        return dp[n];
    }
    dp[n] = (recursive(n-1) + recursive(n-2));
    return dp[n];
}
int main(void){
    int n;
    cin >> n;
    
    cout << recursive(n) << '\n';
    
    return 0;
}
