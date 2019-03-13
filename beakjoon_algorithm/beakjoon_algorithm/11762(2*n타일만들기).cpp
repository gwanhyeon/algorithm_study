//
//  11762(2*n타일만들기).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/01/2019.
//  Copyright © 2019 kgh. All rights reserved.
// 같은형태가 아니여야하므로 확인을 잘해야함
// 타일에서 n -> n ~ M 까지의 값을 확인하면서 타일이 들어갈 수 있는 경우의 조건을 잘따진다.

#include <stdio.h>
#include <iostream>
using namespace std;

int d[1001];
// 중요한것은 !! dp에 있어서
// 점화식으로 도출할 수 있는 능력이 필요하다

int dp(int x){
    // 경우의 존재 종료되는 조건으로 넣어준다.
    if(x==1){
        return 1;
    }
    if(x==2){
        return 2;
    }
    if(d[x] != 0){
        return d[x];
    }
    // 나머지값을 출력하라는 값이 커질 수 있는 경우이다.
    // overflow 방지하기
    return d[x] = (dp(x-1) + dp(x-2)) % 10007;
}
int main(void){
    int x;
    scanf("%d",&x);
    printf("%d",dp(x));
    
    
    
    return 0;
    
}

