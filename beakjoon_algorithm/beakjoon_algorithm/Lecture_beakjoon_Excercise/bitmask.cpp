//
//  bitmask.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(void){
    int n=3;
    
//    cout << (1<<2);
    long long pwd_value = pow(2,20);
    long long sqrt_value = sqrt(pwd_value);
    cout << pwd_value << '\n';
    cout << sqrt_value << '\n';
    cout << (1<<20) -1 << '\n';
    cout << (1<<20) << '\n';
    
    cout << (1<<21) -1 << '\n';
    cout << (1<<21) << '\n';
    
//    for(int i=0; i<(1<<n); i++){
//        cout << i;
//    }
//
    
    return 0;
}
