//
//  2*n타일링.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
/*
 1) 2*n 크기 직사각형  1*2 / 2*1
 2) 내가 생각하였던것은 맨처음에 1*2의 경우의 수와 그다음 2*1 경우의 수 까지 생각을 하였는데,
 그다음을 내가 인위적으로 그 나머지 값들에 대한 규칙을 찾고 있었다.
 3) 규칙자체가 2*n에 대한 것으로 식을 세우고 풀었어야하는데, 나머지 값들에 대한 규칙을 찾고 있었음.
 4) 2*1을 1을 기본으로 둔다는 생각으로 문제를 풀면된다.
 5) n == 2일경우 return 을 2를 왜 해주는것일까? 라고 생각할지 모르겠지만,
 2*n의 타일에 1*2 , 2*1 을 가지고 타일을 만드는 방법의 수라고 생각하면 된다.
 직접 그려보셔야한다.
 
 
 
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int dp[1001];
int recursive(int n){
    
    //N이 1일경우
    if(n == 1){
        cout << "A " << dp[n];
        return 1;
    }
    //N이 2일경우 (1*2, 2*1)의 두가지 경우이므로
    if(n == 2){
        cout << "B " << dp[n];
        return 2;
    }
    
    //이미 타일을 만들었던 경우의 수라면 기존값 리턴
    
    if(dp[n] > 0){
        cout << "C " << dp[n];
        return dp[n];
    }
    
    // DP값에 10007을 나눈 나머지를 구하라고 하였죠.
    dp[n] = (recursive(n-1) + recursive(n-2)) % 10007 ;
    cout << "D " <<  dp[n];
    return dp[n];

}

int main(void){
    
    int n;
    cin >> n;
    int result = recursive(n);

    cout << result ;
    return 0;
    
}


