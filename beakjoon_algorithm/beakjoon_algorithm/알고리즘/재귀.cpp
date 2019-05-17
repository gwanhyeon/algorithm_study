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

long long func1(long long a,long long b,long long c){
    long long val = 1;
    
    while(b--){
        val = (val * a) % c;
    }
    
    return val;
}
long long POW1(long long a, long long b, long long m){
    long long val = pow(a,b/2);
    val = val * val % m;
    
    if(b%2 == 0){
        return val * val;
    }
    
    return val * val * a % m;
}

int main(void){
    cout << func1(6,12,5);
    cout << pow(2, 10);
    
    
    return 0;
}
