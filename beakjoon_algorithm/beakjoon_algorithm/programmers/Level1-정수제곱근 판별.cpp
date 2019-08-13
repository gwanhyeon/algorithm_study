//
//  Level1-정수제곱근 판별.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long cand = sqrt(n);
    if(pow(cand,2) == n) {
        answer = pow(sqrt(n)+1, 2);
    } else {
        answer = -1;
    }
    
    return answer;
}
int main(void){
    int n = 121;
    cout << solution(n) << '\n';
    
}
