//
//  1208 부분수열의 합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
// * 틀렸습니다 *

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void){
    int n,s;
    vector<int> v;
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
        
    }
    int cnt =0;
    int sum = v[0];
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            sum += v[j];
            if(sum == s){
                cnt++;
                sum =0;
            }
            else if(sum > s){
                continue;
            }else if(sum < s){
                continue;
            }
        }
    }
    cout << cnt << '\n';
    
    
    return 0;
    
}
