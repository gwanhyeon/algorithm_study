//
//  14579 덧셈과 곱셈.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    long long sum= 0;
    long long result = 1;
    for(int i=0; i<a; i++){
        sum += i+1;
    }

    for(int i=a; i<=b; i++){
        sum += i;
        result = result * (sum % 14579);
        result %= 14579;
    }
    cout << result << '\n';

    return 0;
}
