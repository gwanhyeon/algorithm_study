//
//  Level1-약수의합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int n = 12;
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            sum += i;
            
        }
    }
    cout << sum;
    return 0;
}
