//
//  recursive 재풀이 14888 연산자 끼워넣기.cpp
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
int max_num = -1e9;
int min_num = 1e9;
vector<int> ans;
int n;
void solve(int idx, int sum, int plus, int minus, int multi, int div, vector<int> v){
    
    if(idx == n){
        ans.push_back(sum);
//        if(sum > max_num){
//            max_num = sum;
//        }
//        if(sum < min_num){
//            min_num = sum;
//        }
        return;
    }
    
    if(plus > n-1){
        solve(idx+1, sum+v[idx], plus-1, minus, multi, div,v);
    }
    if(minus > n-1){
        solve(idx+1, sum-v[idx], plus, minus-1, multi, div,v);
    }
    if(multi > n-1){
        solve(idx+1, sum*v[idx], plus, minus, multi-1, div,v);
        
    }if(div > n-1){
        solve(idx+1, sum/v[idx], plus, minus, multi, div-1,v);
        
    }
}
int main(void){
    ios::sync_with_stdio(false);
    
    cin >> n;
    vector<int> v(n);
    vector<int> oper(4);
    
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<4; i++){
        cin >> oper[i];
    }
    
    solve(1, v[0], oper[0], oper[1], oper[2], oper[3], v);
//    cout << max_num << '\n' << min_num << '\n';
    auto res = minmax_element(ans.begin(), ans.end());
    cout << *res.second <<'\n';
    cout << *res.first << '\n';
    
    return 0;
}
