//
//  피보나치.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>

int arr[10000];

// 0 1 1 2 3 5 8 13 20 .... 피보나치 수열에 대한 규칙을 찾아 내는것이 중요하다
// 피보나치 수열을 구하기 위해서
// n = n-2 + n-2 를 더하게 되면 규칙을 찾아 낼 수 있다.


// 값을 저장시켜놓기 위해서 dp 배열 선언
int dp(int d){
    
    if(d == 1){
        return 1;
    }
    if(d == 2){
        return 1;
    }
    // 기본값으로 0으로 초기화가 되었으므로 기존값 반환
    if(arr[d] != 0){
        return arr[d];
    }
    // dp[d] == 0 일경우 새로 값을 구하게 된다.
    return arr[d] = dp(d-1) + dp(d-2);
    
}

int main(void){
    
    printf("%d",dp(10));
    
    return 0;
    
}
