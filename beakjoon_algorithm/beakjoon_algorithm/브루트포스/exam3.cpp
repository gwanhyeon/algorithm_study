//
//  exam3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101];
int n;
int recursive(int m,int n){
    
    if(n == 0){
        return n;
    }
    if(dp[n]){
        return dp[n];
    }
    
    dp[n] = recursive(m,dp[m-n]);
    return dp[n];
}

int main(void){
    
    int a,b;
    cin >> n;
    int result;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        result = recursive(a,b);
        cout << result;
    }
    
    cout << result;
    
    return 0;
}
