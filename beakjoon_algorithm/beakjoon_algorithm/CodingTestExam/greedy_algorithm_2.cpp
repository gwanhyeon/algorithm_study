//
//  greedy_algorithm_2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int n, result = 0;      // n 입력 돈 , result = 몇개의 동전을 차지하는지.
    cin >> n;       // 1260원
    
    result += n / 500;
    n %= 500;
    result += n / 100;
    n %= 100;
    result += n / 50;
    n %= 50;
    result += n / 10;
    
    cout << result << endl;
    
    
}
