//
//  SWM대비- 최대공약수,최소공배수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    
    if(b == 0){
        return a;
    }else{
    return gcd(b, a % b);
    }
    
}
int main(void){
    
    int a = 24;
    int b = 8;
    
    // 최대 공약수
    int g = gcd(a,b);
    cout << g << endl;
    // 최소 공배수
    // 유클리드 호제법
    int l = g * (a/g) * (b/g);
    
    cout << l;
    return 0;
}


