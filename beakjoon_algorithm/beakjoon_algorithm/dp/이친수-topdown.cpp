//
//  이친수-topdown.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 18/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// todo 시간복잡도 2^n  (1 <= n <= 90) 까지이므로
// int 형의 시간복잡도인 -21억 ~ 21억 초과하게 된다.
// long long 시간복잡도  –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
long long dp[91];
long long recursive(int n){
    
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n]){
        return dp[n];
    }
    dp[n] = recursive(n-1) + recursive(n-2);
    return dp[n];
}

int main(void){
    int n;
    cin >> n;
    
    long long result = recursive(n);
    
    cout << result;
    
    return 0;
}
