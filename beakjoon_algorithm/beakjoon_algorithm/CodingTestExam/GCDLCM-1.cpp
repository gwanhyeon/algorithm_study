//
//  GCDLCM-1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    
    if(b == 0){
        return a;
    }else {
        return gcd(b,a%b);
    }
}

// 24 16
// 16 24%16 = 8
// 8 0 => 0
int main(void){
    int a,b;
    
    cin >> a >> b;
    
    // 최대 공약수 GCD
    int g = gcd(a,b);
    cout << g << endl;
    
    
    // 최소 공배수 LCM
    int l = g * (a/g) * (b/g);
    cout << l << endl;
    
    
    
    return 0;
}
