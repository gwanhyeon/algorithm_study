//
//  7453 합이 0인 네정수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 18/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    
    vector<int> a; vector<int> b;
    vector<int> c; vector<int> d;
    
    for(int i=0; i<n; i++){
        int a_x, b_x, c_x, d_x;
        cin >> a_x >> b_x >> c_x >> d_x;
        a.push_back(a_x);
        b.push_back(b_x);
        c.push_back(c_x);
        d.push_back(d_x);
    }
    
    vector<int> first;
    vector<int> second;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            first.push_back(a[i] + b[j]);
            second.push_back(c[i] + d[j]);
        }
    }
    
//    sort(first.begin(),first.end());
    sort(second.begin(), second.end());
    long long ans = 0;
    
    for(int i=0; i<first.size(); i++){
        auto p = equal_range(second.begin(), second.end(), -first[i]);
            ans += p.second - p.first;
    }
    cout << ans << '\n';
    return 0;
}
