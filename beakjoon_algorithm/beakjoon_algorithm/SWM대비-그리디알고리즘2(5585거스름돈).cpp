//
//  SWM대비-그리디알고리즘2(5585거스름돈).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
// 500 / 100 / 50 / 10 / 5 /1 엔
// 가장 최소의 거스름 개수 => 1000엔 지폐 한장일 경우
#include <iostream>
using namespace std;
int main(void){
    int n = 0;
    int result = 0;
    
    cin >> n;
    
    // 중요 ** 1000원을 건네주었을때 - n개의 거스름돈의 화폐의 개수를 구하는것이므로 꼭 여기 주의.**
    n = 1000 - n;
    
    result += (n / 500);
    n %= 500;
    
    result += (n / 100);
    n %= 100;
    
    result += (n / 50);
    n %= 50;
    
    result += (n / 10);
    n %= 10;
    
    result += (n / 5);
    n %= 5;
    
    result += (n / 1);

    cout << result;
    return 0;
}
