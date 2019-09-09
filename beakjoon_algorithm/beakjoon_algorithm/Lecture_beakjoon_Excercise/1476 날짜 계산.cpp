//
//  1476 날짜 계산.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 09/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int E,S,M;
    cin >> E >> S >> M;
    int e = 1;
    int s = 1;
    int m = 1;
    // 111로 시작
    int result = 1;
    while(true){
        if(e > 15){
            e = 1;
        }
        if(s > 28){
            s = 1;
        }
        if(m > 19){
            m = 1;
        }
        if(E == e && S == s && M == m){
            cout << result;
            break;
        }
        result++;
        e++;
        s++;
        m++;
    }
    
    
    
    
    return 0;
}
