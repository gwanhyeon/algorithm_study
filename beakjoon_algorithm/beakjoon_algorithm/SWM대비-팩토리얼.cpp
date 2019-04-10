//
//  SWM대비-팩토리얼.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int fact(int n){
    
    // n이 0일경우에 프로그램 종료 시키고,
    if(n == 0){
        return 1;
    }
    // 아닐경우에 n 부터 시작해서 fact(n-1) 까지 recursive 를 통해서 값을 계속 구해온다.
    return n * fact(n-1);
}
int main(void){
    
    int n =5;
//    cin >> n;

    cout << fact(n);
    
    
    return 0;
}
