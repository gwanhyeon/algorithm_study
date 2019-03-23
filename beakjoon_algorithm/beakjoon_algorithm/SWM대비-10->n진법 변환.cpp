//
//  SWM대비-진법 변환.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


//10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
// 진법이란? a % b를 나눈 나머지 의 값

int main(void){
    
    int n,b = 0;
    string str;   // ** string 선언 필수다!!!!!!!!!
    
    cin >> n >> b;
    // r = number % b

    
    while(n > 0){
        int r = n % b;
        // 10이상일경우 대문자 변경
        if(r >= 10){
            str += (char)(r-10+'A');
        }
        // 10이하일경우 그대로 문자열로만 변경
        // '0'을 빼주면
        else{
            str += (char)(r+'0');
        }
        // 값 갱신
        n /= b;
    }
    cout << str;
    
    
    
}
