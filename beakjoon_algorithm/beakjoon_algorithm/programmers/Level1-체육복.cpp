//
//  Level1-체육복.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
bool check[30];
using namespace std;
int main(void){
    int n=5;
    vector<int> lost;
    vector<int> reserve;
    lost.push_back(2);lost.push_back(2);        // lost st
    reserve.push_back(1); reserve.push_back(3); // reverse st
    reserve.push_back(5);
    
    int cnt=0;
    
    for(int i=0; i<n; i++){
        if(reserve[i]-1 == lost[i] ||
           reserve[i]+1 == lost[i]){
            cnt++;
        }
    }
    cout << cnt + reserve.size();
    
    return 0;
}
