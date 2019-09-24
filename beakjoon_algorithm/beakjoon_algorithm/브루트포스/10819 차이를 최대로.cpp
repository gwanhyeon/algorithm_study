//
//  10819 차이를 최대로.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 18/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> result(n);
    
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    do{
        int ans =0;
        for(int i=1; i<n; i++){
            ans += v[i];
        }
        result.push_back(ans);
    }while(next_permutation(v.begin(),v.end()));
    
    auto &p = *max_element(result.begin(),result.end());
    cout << p << '\n';
}

