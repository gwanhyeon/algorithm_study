//
//  nevelcup_A.cpp
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 5. 7..
//  Copyright © 2018년 kgh. All rights reserved.
//
//
//두 정수 a와 b를 곱한 값이, r보다 큰지 판단하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 정수 a, b, r이 공백으로 구분되어 주어진다. (0 ≤ a, b ≤ 1020, 0 ≤ r < 263)
//
//각 정수 a, b, r이 0인 경우를 제외하고, 0으로 시작하는 입력은 주어지지 않는다.
//
//출력
//a와 b를 곱한 값이 r보다 크면 overflow를, 그렇지 않다면 a와 b를 곱한 값을 출력하라.



#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int a,b,r;
    int result;
    
    
    scanf("%d %d %d",&a,&b,&r);
    if(a == b == r == 0){
        
    }else if(a == 0){
        scanf("%d %d %d",&a,&b,&r);
    }

    result = a * b;
    
    if(result > r){
        printf("overflow");
    }else{
        printf("%d",(a*b));
    }
    
}
