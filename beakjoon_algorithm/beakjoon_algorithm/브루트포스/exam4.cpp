
//
//  exam4.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        
        cin >> v[i];
    }
    vector<int> res;
    
    for(int i=0; i<n; i++){
        if(v[i] == 1){
            for(int j=i+1; j<n; j++){
                if(v[j] == 1){
                    res.push_back(j);
                }
            }
        }
    }
    auto &p = *min_element(res.begin(),res.end());
    
    
    cout << p << '\n';
    return 0;
    
}
