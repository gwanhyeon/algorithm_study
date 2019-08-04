//
//  GDC-2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//재귀 함수를 이용한 유클리드 호제법 사용하기


int gcd(int a,int b){
    if(b == 0){
        return a; // a값이 나머지니까
        
    }else{
        // 유클리드 호제법 적용하기
        return gcd(b,a%b);
    }
    
}
int main(void){
    int a=24;
    int b=16;
    
    // 유클리드 호제법 적용하기
    int g = gcd(a,b);
    cout << g << endl;
    return 0;
}
