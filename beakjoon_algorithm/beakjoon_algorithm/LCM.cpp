//
//  LCM.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    
    // 유클리드 호제법 재귀함수
    // 예제 24 16
    if(b == 0){
        return a;
    }else {
        return gcd(b,a%b);
    }
}
int main(void){
    int n;
    cin >> n;
    
    while(n--){
        int a,b;
        cin >> a >> b;
        int g = gcd(a,b);
        int l = g * (a/g) * (b/g);
        cout << l << endl;
    }
    
    return 0;
}
