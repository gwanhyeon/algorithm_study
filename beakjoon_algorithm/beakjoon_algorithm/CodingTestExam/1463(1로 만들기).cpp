//
//  1463(1로 만들기).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1001];

int recursive(int n){
    
    // 1일 경우
    if(n == 1){
        return 0;
    }
    // 값이 있는 경우
    if(dp[n] > 0){
        return dp[n];
    }
    // 1. 1을 뺐을 경우
    dp[n] = recursive(n-1) + 1;
    
    // 2. 나누었을때 2가 되는경우
    if(n % 2 == 0){
        int temp = recursive(n/2) + 1;
        // 최소값으로 만들어 준다.
        if(dp[n] > temp){
            dp[n] = temp;
        }
    }
    // 3. 나누었을때 3이 되는 경우
    if(n % 3 == 0){
        int temp = recursive(n/3) + 1;
        // 최소값을 으로 만들어 준다.
        if(dp[n] > temp){
            dp[n] = temp;
        }
        
    }
    return dp[n];
}
int main(void){
    int n;
    cin >> n;
    recursive(n);
    
    
    
    return 0;
}
