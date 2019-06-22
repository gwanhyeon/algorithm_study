//
//  prime_factorization.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 16/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 소인수 분해 문제

int main(void){
    
    int n;
    cin >> n;
    for(int i=2; i*i <=n; i++){
        while(n % i == 0){
            // 소인수 분해 값 출력 하는것.
            cout << i << "\n";
            n /= i;
        }
    }
    if(n > 1){
        cout << n;
    }
}
