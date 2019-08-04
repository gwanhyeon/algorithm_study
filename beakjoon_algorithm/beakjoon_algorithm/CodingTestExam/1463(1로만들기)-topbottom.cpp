//
//  1463(1로만들기).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 24/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


// TOP - BOTTOM 방식 큰 문제 dp[100001] -> 작은문제로
int dp[1000001];

int recursive(int num){
    
    // 1일 경우 순회하지 않고 종료
    if(num == 1){
        return 0;
    }
    // dp값이 0보다 큰 경우(값이 있는경우== 값이 저장되어있는경우)
    if(dp[num] > 0){
        return dp[num];
    }
    // 10의 경우를 대비해서 num % 3, num % 2 , num -1 의 경우가 아니라
    // 1. num - 1을 기본적으로 깔고 들어가서 값을 저장시켜놓기 위함
    dp[num] = recursive(num-1) + 1;
    // 2.  num % 3으로 나누어질 경우
    if(num % 3 == 0){
        int save = recursive(num/3) + 1;
        // 왜 값을 비교하고 다시 저장하느냐? 최소값을 구하기 위함입니다. num/3으로 나눈 값이 dp[num]값보다 작으면 최소값이 되기때문입니다.
        if(dp[num] > save){
            dp[num] = save;
        }
    }
    // 3. num % 2으로 나누어질 경우
    if(num % 2 == 0){
        int save = recursive(num/2) + 1;
        // 왜 값을 비교하고 다시 저장하느냐? 최소값을 구하기 위함입니다. num/2으로 나눈 값이 dp[num]값보다 작으면 최소값이 되기때문입니다.
        if(dp[num] > save){
            dp[num] = save;
        }
        
    }
    return dp[num];
    
}
int main(void){
    int num;
    cin >> num;
    cout << recursive(num) << endl;

    return 0;
}




