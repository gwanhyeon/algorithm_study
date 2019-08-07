//
//  Level1-소수찾기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void){
    
    bool check[1000001] = {false,};
    int n = 10;
    int sum = 0;
    for(int i=2; i<=n; i++){
        if(!check[i]){
            sum++;
        }
        for(int j=i; j<=n; j+=i){
            cout << "j : " << j;
            check[j] = true;
        }
    }
    
    cout << sum;
    return 0;
}

