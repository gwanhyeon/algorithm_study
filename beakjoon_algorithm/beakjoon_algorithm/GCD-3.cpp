//
//  GCD-3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
// 재귀 함수를 사용하지 않고 나머지 구하는방법

int gcd(int a,int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    // a값을 리턴하는 이
    return a;
}
int main(void){
    int a=24;
    int b=16;
    

    
    
    
    
    return 0;
}
