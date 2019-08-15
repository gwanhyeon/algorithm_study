//
//  double_test.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    float a = 2.0;
    float b = 3.0;
    
    float result = a * b;
    cout.precision(6); 
    cout << fixed << result << endl;
    printf("%f",result);
    
    return 0;
}
