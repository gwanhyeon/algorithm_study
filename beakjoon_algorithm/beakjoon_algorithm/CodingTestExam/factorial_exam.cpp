//
//  factorial_exam.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 16/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
int main(void){
    
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}


