//
//  greedy_algorithm_3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int n;
    int result = 0;
    cin >> n;
    n = n - 1000;
    
    n %= 500;
    result += n / 500;
    
    n %= 100;
    result += n / 100;
    
    n %= 50;
    result += n / 50;
    
    n %= 10;
    result += n / 10;
    
    n %= 5;
    result += n / 5;
    result += n / 1;
    
    cout << result;
    return 0;
}
