//
//  TestCase.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int num = 33;
    
    int sum = num % 10;
    int sum1 = num / 10;
    int sum2 = sum1 / 10;
    
    cout << sum << endl;
    cout << sum1 << endl;
    cout << sum2 << endl;
    
    return 0;
}

