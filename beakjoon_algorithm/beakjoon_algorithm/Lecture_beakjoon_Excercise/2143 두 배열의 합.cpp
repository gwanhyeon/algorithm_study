//
//  2143 두 배열의 합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int t,num_a,num_b;
    cin >> t;
    
    // a의 부분 배열
    cin >>num_a;
    vector<int> v1(num_a);
    for(int i=0; i<num_a; i++){
        cin >> v1[i];
    }
    // b의 부분 배열
    cin >> num_b;
    vector<int> v2(num_b);
    for(int i=0; i<num_b; i++){
        cin >> v2[i];
    }
    vector<int> first;
    for(int i=0; i<num_a; i++){
        int sum = 0;
        for(int j=i; j<num_a; j++){
            sum += v1[j];
            first.push_back(sum);
        }
    }
    
    vector<int> second;
    for(int i=0; i<num_b; i++){
        int sum = 0;
        for(int j=i; j<num_b; j++){
            sum += v2[j];
            second.push_back(sum);
        }
    }
    
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    long long ans = 0;
    
    for(int i=0; i<first.size(); i++){
        auto p = equal_range(second.begin(),second.end(),t-first[i]);
        ans += p.second - p.first;
    }
    cout << ans << '\n';
    return 0;
    
}
