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
 
 
*/
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
    if(dp[n] > 0){
        return dp[n];
    }
    
    dp[n] = (recursive(n-1) + recursive(n-2)) % 10007 ;
    return dp[n];
    
    
    
}
int main(void){
    int n;
    cin >> n;
    int result = recursive(n);
    
    cout << result ;
    

    return 0;
}


