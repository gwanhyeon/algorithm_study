//
//  RGB거리.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// 빨 초 파


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int dp[1001];
int main(void){
    
    int n;
    cin >> n;
    
    for(int i=0; i<v.size(); i++){
        cin >> v[i];
    }
    
    for(int i=1; i<=v.size(); i++){
        for(int j=1; j<=v.size(); j++){
//            if(i > j){
                dp[i] = min(dp[i],dp[2*j]+v[j]);
//            }
        }
    }
    
    cout << dp[n];
    
    
    
    
    return 0;
}
