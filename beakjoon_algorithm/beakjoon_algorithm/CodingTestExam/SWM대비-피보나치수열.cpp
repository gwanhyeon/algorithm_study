//
//  SWM대비-피보나치수열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int memo[1001];

// 피보나치 전형적인 dp 문제이다. memorization 문제이므로 한번 시험보기 전에 한번더 보자!!!
int fibonachi(int n){
      // 1보다 작으면 n반환 !!!!!!
    if(n <= 1){
        return n;
    }else{
        // memo의 값이 있을경우 메모이제이션 처리한다.
        if(memo[n] > 0 ){
            return memo[n];
        }
        // 피보나치 수열 처리 해주기.!
        memo[n] = fibonachi(n-1) + fibonachi(n-2);
        return memo[n];
    }

}
int main(void){
    
    int n = 5;
    cout << fibonachi(n);
    return 0;
}
