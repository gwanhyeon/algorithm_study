//
//  1463(1로만들기)-bottomup.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 26/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

// BOTTOM UP 문제

#include <stdio.h>
#include <iostream>
using namespace std;

int dp[1000001];

int main(void){
    int num;
    cin >>num;
    // 가장 작은 문제를 1로 둔다. 왜? 여기서 원하고하자는것은 1에 최소횟수이므로, dp[num==1]일 경우를 가장 작은문제로 두고 푸는것임.
    dp[1] = 0;
    
    // 가장 작은문제로 두었기때문에 그다음문제부터 입력한 수까지의 값을 반복문을 돌리게 한다.
    for(int i=2; i<=num; i++){
        dp[i] = dp[i-1] + 1;
        
        // i를 3으로 나누었을때 0 이며, 나눈값이 기존의 dp[num]값보다 작을때 값을 바꿔준다.(최소값)
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] +1;
            
        }
        // i를 2으로 나누었을때 0 이며, 나눈값이 기존의 dp[num]값보다 작을때 값을 바꿔준다.(최소값)
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
        }
    }
    
    // 출력
    cout << dp[num] << endl;
  
    return 0;
}
