//
//  재귀.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int recursive(int val){
    
    if(val == 1) {
        return 0;
    }
    return val * recursive(val-1);
    
}

int main(void){
    cout << recursive(5);
    
    
    
    return 0;
}
