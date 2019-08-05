//
//  Level1-두정수사이의합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int a = 3;
    int b = 5;
    long long answer = 0;
    if(a > b){
        // 5 4 3
        for(int i=a; i>=b; i--){
            answer += i;
        }
        
    }else {
        for(int i=a; i<=b; i++){
            answer += i;
        }
    }
    cout << answer;
    return 0;
    
}
