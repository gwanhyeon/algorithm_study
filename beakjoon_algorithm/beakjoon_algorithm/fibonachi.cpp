//
//  fibonachi.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// dp에서 가장 중요한 점은 중복을 제외할 수 있는 memorization을 잘 확인하여야한다.
int memo[10001];
// top down , bottom up 중에 사용하고 싶은것들을 사용한다.

// n은 몇번째 까지 피보나치 수열을 구할 건지의 값을 말한다.
int fibonachi(int n){
    // 1보다 작을 경우
    if(n <= 1){
        return n;
    }else{
        // 메모이 제이션값이 있을 경우
        if(memo[n] > 0 ){
            return memo[n];
        }
        // 값이 저장된 상태라면 이미 memo배열에는 default값인 0이 차지하고 있으므로,
        // 재귀함수를 통하여 다시 재호출 하면서 값을 받아오게 된다.
        
        memo[n] = fibonachi(n-1) + fibonachi(n-2);
        return memo[n];
    }
    
}

int main(void){
    int n;
    cin >> n;
    int num = fibonachi(n);
    cout << num;
    
    
    
    return 0;
    
    
}
