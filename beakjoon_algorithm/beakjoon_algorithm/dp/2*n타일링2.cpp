//
//  2*n타일링2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1001];
int recursive(int n){
    // N == 1 한가지 경우 2*1
    if(n == 1){
        return 1;
    }
    // N == 2 1*2 , 2*1 , 2*2 3가지 경우 리턴
    if(n == 2){
        return 3;
    }
    // 값 존재시 dp[n] 리턴 메모이 제이션
    if(dp[n] > 0){
        return dp[n];
    }
    // 아까 구한 점화식 적용
    dp[n] = (recursive(n-1) + (2* recursive(n-2))) % 10007;
    return dp[n];
}
int main(void){
    int n;
    cin >> n;
    
    // 최종 경우의 수 출력
    int result = recursive(n);
    cout << result;
    
    return 0;
    
}
