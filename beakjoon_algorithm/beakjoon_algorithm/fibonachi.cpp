//
//  fibonachi.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[100];

int fibo(int num){
    
    if(num == 1){
        return 1;
    }
    if(num == 2){
        return 1;
    }
    
    if(dp[num] != 0){
        return dp[num];
    }
    
    return dp[num] = fibo(num-2) + fibo(num-1);
    
}

int main(void){
    int num = 30;
    int result=0;
    result = fibo(num);
    
    cout << result;
    return 0;
}
