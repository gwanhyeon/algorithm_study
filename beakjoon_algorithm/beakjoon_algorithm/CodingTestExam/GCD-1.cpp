//
//  GCD-1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 일반적인 최대 공약수 GDC 구하는 방법
int main(void){
    int g = 1;
    int a=24;
    int b=16;
    
    for(int i=2; i<=min(a,b); i++){
        if(a % i == 0 && b % i == 0){
            g = i;
        }
    }
    cout << g <<endl;
    return 0;

}
