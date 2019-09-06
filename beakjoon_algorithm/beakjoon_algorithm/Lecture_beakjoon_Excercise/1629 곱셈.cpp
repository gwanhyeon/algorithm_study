//
//  1629 곱셈.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long result = 0;
    for(int i=0; i<b; i++){
        result += (a*a) % c;
    }
    cout << result %c<< endl;
    
    
    return 0;
}
