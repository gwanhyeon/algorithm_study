//
//  recursive 15658번 연산자 끼워넣기2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 26/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> res;

void recursive(int idx, int sum, int plus, int minus, int mul, int div, vector<int> v){
    
    // 정답일 경우
    if(idx == n){
        res.push_back(sum);
        return;
    }
    // 정답이 아닐 경우
    
    if(plus < 0 || minus < 0 || mul < 0 || div < 0){
        return;
    }
    if(plus != 0){
        recursive(idx+1, sum+v[idx],plus-1, minus, mul, div, v);
    }
    if(minus != 0){
        recursive(idx+1, sum-v[idx],plus, minus-1, mul, div, v);
    }
    if(mul != 0){
        recursive(idx+1, sum*v[idx],plus, minus, mul-1, div, v);
    }
    if(div != 0){
        recursive(idx+1, sum/v[idx], plus, minus, mul, div-1, v);
    }
    
}


int main(void){
    ios::sync_with_stdio(0);
    cin >> n;
    vector<int> v(n);
    vector<int> op(4);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    recursive(1,v[0], op[0], op[1], op[2], op[3], v);
    
    auto p = minmax_element(res.begin(),res.end());
    cout << *p.second << '\n' << *p.first << '\n';
    
    
    
    
    
    
    return 0;
}
