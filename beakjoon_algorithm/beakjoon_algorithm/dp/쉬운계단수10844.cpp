//
//  쉬운계단수10844.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 1~n(1<=n<=100) , 1~9 까지의 계단수
// ***** 인접한 모든수의 차이가 1이난다!

long long dp[101][10];
long long mod = 1000000000;
int main(void){
    int n;
    cin >> n;
    
    // 0으로 시작하는 수가 없으니까 1인 수의 계단수는 1개이므로
    
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }
    
    /*
     N = 1
     => 1, 2,3,4,5,6,7,8,9
     N =2
     => 10,12, 21, 23 ,32 ,34 43, 45
     
     1) 이때 주의 할점은 문제에서 1은 계단수가 아니라고 정의 하였고
     2) 따라서, 점화식 L(1~8일때만 성립한다)
     3) 0이라고 하는것은 범위가 dp[1]만 허용되고,  9 는 -1을 한 8만 허용되므로
     
     
     */
    // 총 n의 계단수 찾기 위함
    for(int i=2; i<=n; i++){
        // 1~9까지의 값
        for(int j=0; j<=9; j++){
            dp[i][j] = 0;
            // n-1의 경우
            if(j-1 >= 0){
                dp[i][j] += dp[i-1][j-1];
            }
            // n+1의 경우
            if(j+1 < 10){
                dp[i][j] += dp[i-1][j+1];
            }
            // mod로 나눈 경우
            dp[i][j] %= mod;
        }
    }
    
    long long ans = 0;
    for(int i=0; i<=9; i++){
        ans += dp[n][i];        // 1~n까지의 수중에 계단수의 개수를 뽑아내기위해.
    }
    ans %= mod;
    cout << ans << '\n';
    
    return 0;
}

