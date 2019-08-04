//
//  numeral_system.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    
    string mark_str = "0123456789ABCDEF";
    string mark_str_convert;

    int num;
    int base;
    
    scanf("%d %d",&num,&base);
    
    while(num > 0){
        mark_str_convert += mark_str[num % base]; // 나눈 나머지 값으로 갱신한다
        num /= base;        // 진법으로 나눈값으로 업데이트
    }
    reverse(mark_str_convert.begin(),mark_str_convert.end());
    cout << mark_str_convert;
    
    return 0;
    
}
